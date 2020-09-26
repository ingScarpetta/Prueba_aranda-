//
// Created by lenovo on 24/9/2020.
//

#include "gtest/gtest.h"
#include <cpprest/http_client.h>
#include <cpprest/json.h>
#include <iostream>

#include "ServiciosAPI.h"

using namespace API;


TEST( PruebaApi , NumeroUno) {
    // Se crea servidor
    ServiciosAPI servidor(U("localhost"), 8080);
    servidor.Subir();
    // Se crea Cliente
    web::http::client::http_client cliente(U("http://localhost:8080/"));
    // Se crean datos de creacion de arbol
    web::json::value datosCrear;
    datosCrear[U("valores")] = web::json::value::array({1,2,3,4});
    // Se crea consulta
    web::http::http_request solicitudCrear(web::http::methods::PUT);
    solicitudCrear.set_request_uri(U("crear"));
    solicitudCrear.set_body(datosCrear);
    auto respuestaCrear = cliente.request(solicitudCrear).get();
    // Se procesa respuesta de creación
    EXPECT_EQ( respuestaCrear.status_code(),200);
    auto jsonCrear = respuestaCrear.extract_json().get();
    EXPECT_TRUE(jsonCrear.has_integer_field(U("id")));
    if (!jsonCrear.has_integer_field(U("id"))) {
        return;
    }
    int idCreado = jsonCrear[U("id")].as_integer();
    EXPECT_GT(idCreado, 0);
    if (idCreado <= 0) {
        return;
    }
    // Se crean datos para buscar ancestro
    web::json::value datosAncestro;
    datosAncestro[U("id")] = idCreado;
    datosAncestro[U("nodo1")] = 3;
    datosAncestro[U("nodo2")] = 4;
    // Se consulta ancestro
    web::http::http_request solicitudBuscar(web::http::methods::POST);
    solicitudBuscar.set_request_uri(U("buscar-ancestro"));
    solicitudBuscar.set_body(datosAncestro);
    auto respuestaBuscar = cliente.request(solicitudBuscar).get();
    // Se procesa respuesta de Buscar Ancestro
    EXPECT_EQ( respuestaBuscar.status_code(),200);
    auto jsonBuscar = respuestaBuscar.extract_json().get();
    EXPECT_TRUE(jsonBuscar.has_integer_field(U("ancestro")));
    if (!jsonBuscar.has_integer_field(U("ancestro"))) {
        return;
    }
    int ancestro = jsonBuscar[U("ancestro")].as_integer();
    EXPECT_EQ(ancestro, 3);
    // Se detiene servidor
    servidor.Bajar();
}
TEST( PruebaApi , NumeroDos) {
    // Se crea servidor
    ServiciosAPI servidor(U("localhost"), 8080);
    servidor.Subir();
    // Se crea Cliente
    web::http::client::http_client cliente(U("http://localhost:8080/"));
    // Se crean datos de creacion de arbol
    web::json::value datosCrear;
    datosCrear[U("valores")] = web::json::value::array({1,2,3,4});
    // Se crea consulta
    web::http::http_request solicitudCrear(web::http::methods::PUT);
    solicitudCrear.set_request_uri(U("crear"));
    solicitudCrear.set_body(datosCrear);
    auto respuestaCrear = cliente.request(solicitudCrear).get();
    // Se procesa respuesta de creación
    EXPECT_EQ( respuestaCrear.status_code(),200);
    auto jsonCrear = respuestaCrear.extract_json().get();
    EXPECT_TRUE(jsonCrear.has_integer_field(U("id")));
    if (!jsonCrear.has_integer_field(U("id"))) {
        return;
    }
    int idCreado = jsonCrear[U("id")].as_integer();
    EXPECT_GT(idCreado, 0);
    if (idCreado <= 0) {
        return;
    }
    // Se crean datos para buscar ancestro
    web::json::value datosAncestro;
    datosAncestro[U("id")] = idCreado;
    datosAncestro[U("nodo1")] = 5;
    datosAncestro[U("nodo2")] = 4;
    // Se consulta ancestro
    web::http::http_request solicitudBuscar(web::http::methods::POST);
    solicitudBuscar.set_request_uri(U("buscar-ancestro"));
    solicitudBuscar.set_body(datosAncestro);
    auto respuestaBuscar = cliente.request(solicitudBuscar).get();
    // Se procesa respuesta de Buscar Ancestro
    EXPECT_EQ( respuestaBuscar.status_code(),400);
    auto jsonBuscar = respuestaBuscar.extract_json().get();
    EXPECT_TRUE(jsonBuscar.has_string_field(U("error")));
    if (!jsonBuscar.has_string_field(U("error"))) {
        return;
    }
    const utility::string_t& ancestro = jsonBuscar[U("error")].as_string();
    EXPECT_EQ(ancestro, U("Nodo no encontrado"));
    // Se detiene servidor
    servidor.Bajar();
}
TEST( PruebaApi , NumeroTres) {
    // Se crea servidor
    ServiciosAPI servidor(U("localhost"), 8080);
    servidor.Subir();
    // Se crea Cliente
    web::http::client::http_client cliente(U("http://localhost:8080/"));
    // Se crean datos de creacion de arbol
    web::json::value datosCrear;
    datosCrear[U("valores")] = web::json::value::array({1, 2, 3, 4});
    // Se crea consulta
    web::http::http_request solicitudCrear(web::http::methods::PUT);
    solicitudCrear.set_request_uri(U("crear"));
    solicitudCrear.set_body(datosCrear);
    auto respuestaCrear = cliente.request(solicitudCrear).get();
    // Se procesa respuesta de creación
    EXPECT_EQ(respuestaCrear.status_code(), 200);
    auto jsonCrear = respuestaCrear.extract_json().get();
    EXPECT_TRUE(jsonCrear.has_integer_field(U("id")));
    if (!jsonCrear.has_integer_field(U("id"))) {
        return;
    }
    int idCreado = jsonCrear[U("id")].as_integer();
    EXPECT_GT(idCreado, 0);
    if (idCreado <= 0) {
        return;
    }
    // Se crean datos para buscar ancestro
    web::json::value datosAncestro;
    datosAncestro[U("id")] = 99999;
    datosAncestro[U("nodo1")] = 5;
    datosAncestro[U("nodo2")] = 4;
    // Se consulta ancestro
    web::http::http_request solicitudBuscar(web::http::methods::POST);
    solicitudBuscar.set_request_uri(U("buscar-ancestro"));
    solicitudBuscar.set_body(datosAncestro);
    auto respuestaBuscar = cliente.request(solicitudBuscar).get();
    // Se procesa respuesta de Buscar Ancestro
    EXPECT_EQ(respuestaBuscar.status_code(), 400);
    auto jsonBuscar = respuestaBuscar.extract_json().get();
    EXPECT_TRUE(jsonBuscar.has_string_field(U("error")));
    if (!jsonBuscar.has_string_field(U("error"))) {
        return;
    }
    const utility::string_t &ancestro = jsonBuscar[U("error")].as_string();
    EXPECT_EQ(ancestro, U("Arbol no encontrado"));
    // Se detiene servidor
    servidor.Bajar();
}