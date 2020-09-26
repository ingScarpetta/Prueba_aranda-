//
// Created by lenovo on 24/9/2020.
//

#pragma once

#include <iostream>
#include <cpprest/http_listener.h>
#include "AdministradorArboles.h"

namespace API {
    class ServiciosAPI {
    public:
        ServiciosAPI(const std::wstring& host, unsigned int puerto);

        void Subir();
        void Bajar();

    private:
        web::http::experimental::listener::http_listener _servidor;
        Negocio::AdministradorArboles administrador;

        void ProcesarPOST(web::http::http_request solictud);
        void ProcesarPUT(web::http::http_request solictud);

        static utility::string_t ConstruirURL(const std::wstring& host, unsigned int puerto);

    };
}
