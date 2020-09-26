//
// Created by lenovo on 24/9/2020.
//

#include <functional>

#include "ServiciosAPI.h"
#include <cpprest/http_client.h>
#include <cpprest/json.h>



API::ServiciosAPI::ServiciosAPI(const std::wstring &host, unsigned int puerto)
    : _servidor(ConstruirURL(host,puerto)){
    _servidor.support(web::http::methods::POST,
                      [&](web::http::http_request solicitud) {
                          this->ProcesarPOST(solicitud);});
    _servidor.support(web::http::methods::PUT,
                      [&](web::http::http_request solicitud) {
                          this->ProcesarPUT(solicitud);});
    /*
    _servidor.support(web::http::methods::POST,
                      std::bind(&ServiciosAPI::ProcesarPUT, this, std::placeholders::_1));
                      */

}

void API::ServiciosAPI::Subir() {
    _servidor.open();
}

void API::ServiciosAPI::Bajar() {
    _servidor.close();
}

utility::string_t API::ServiciosAPI::ConstruirURL(const std::wstring &host, unsigned int puerto) {

    return U("http://") + host + U(":") + std::to_wstring(puerto);
}

void API::ServiciosAPI::ProcesarPOST(web::http::http_request solictud) {
    // analizar json
    auto jsonSolicitud = solictud.extract_json().get();
    web::json::value respuesta;
    if (!jsonSolicitud.has_integer_field(U("id"))) {
        respuesta[U("error")] = web::json::value( U("Campo requerido id"));
        solictud.reply(web::http::status_codes::BadRequest,respuesta);
        return;
    }
    if (!jsonSolicitud.has_integer_field(U("nodo1"))) {
        respuesta[U("error")] = web::json::value( U("Campo requerido nodo1"));
        solictud.reply(web::http::status_codes::BadRequest,respuesta);
        return;
    }
    if (!jsonSolicitud.has_integer_field(U("nodo2"))) {
        respuesta[U("error")] = web::json::value( U("Campo requerido nodo2"));
        solictud.reply(web::http::status_codes::BadRequest,respuesta);
        return;
    }

    int id = jsonSolicitud[U("id")].as_integer();
    int nodo1 = jsonSolicitud[U("nodo1")].as_integer();
    int nodo2 = jsonSolicitud[U("nodo2")].as_integer();
    // hacer respuesta
    std::optional<int> ancestro;
    try{
        ancestro = administrador.BuscarAncestro(id,nodo1,nodo2);
    }
    catch (Persistencia::ArbolNoEncontradoExcep& excepcion) {
        std::string mensaje (excepcion.what());
        respuesta[U("error")] = web::json::value( std::wstring(mensaje.begin(), mensaje.end()));
        solictud.reply(web::http::status_codes::BadRequest,respuesta);
        return;
    }
    catch (Persistencia::NodoNoEncontradoExcep& excepcion) {
        std::string mensaje (excepcion.what());
        respuesta[U("error")] = web::json::value( std::wstring(mensaje.begin(), mensaje.end()));
        solictud.reply(web::http::status_codes::BadRequest,respuesta);
        return;
    }
    if (!ancestro) {
        respuesta[U("error")] = web::json::value( U("No se encontró ancestro común más cercano"));
        solictud.reply(web::http::status_codes::BadRequest,respuesta);
        return;
    }
    respuesta[U("ancestro")] = *ancestro;
    solictud.reply(200, respuesta);
}

void API::ServiciosAPI::ProcesarPUT(web::http::http_request solictud) {

    auto jsonSolicitud = solictud.extract_json().get();
    web::json::value respuesta;
    if (!jsonSolicitud.has_array_field(U("valores"))) {
        respuesta[U("error")] = web::json::value( U("Campo requerido valores de tipo Arreglo"));
        solictud.reply(web::http::status_codes::BadRequest,respuesta);
        return;
    }

    auto arreglo = jsonSolicitud[U("valores")].as_array();
    std::list<int> valores;
    for (auto& valor: arreglo) {
        valores.push_back(valor.as_integer());
    }
    // hacer respuesta
    auto arbol = administrador.CrearArbol(valores);
    if (arbol == nullptr) {
        respuesta[U("error")] = web::json::value( U("Error inesperado"));
        solictud.reply(web::http::status_codes::BadRequest,respuesta);
        return;
    }
    respuesta[U("id")] = arbol->GetID();
    solictud.reply(200, respuesta);
}

