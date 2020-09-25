//
// Created by lenovo on 24/9/2020.
//

#include "ServiciosAPI.h"
#include <cpprest/http_client.h>
#include <cpprest/json.h>

using namespace web::http::client;

API::ServiciosAPI::ServiciosAPI(const std::string &host, unsigned int puerto) {
    http_client client(U("http://localhost:8080/"));
    web::http::http_request peticion;
    peticion.set_method(web::http::methods::POST);
    peticion.set_request_uri(U("crear"));
    web::json::value entrada_json;
    entrada_json[U("id")] = 12;
    entrada_json[U("float")] = 12.45;
    entrada_json[U("arreglo")] = web::json::value::array({2, 3, 4, 5});
    utility::string_t nombre(U("Laura mi nombre"));
    entrada_json[U("nombre")] = web::json::value(nombre, false);


    peticion.set_body(entrada_json);
    auto respuesta = client.request(peticion).get();
    auto datos = respuesta.extract_json().get();

}

void API::ServiciosAPI::Subir() {

}

void API::ServiciosAPI::Bajar() {

}
