//
// Created by lenovo on 24/9/2020.
//

#include "ServiciosAPI.h"
#include <cpprest/http_client.h>

using namespace web::http::client;

API::ServiciosAPI::ServiciosAPI(const std::string &host, unsigned int puerto) {
    http_client client(U("http://www.bing.com/"));
}

void API::ServiciosAPI::Subir() {

}

void API::ServiciosAPI::Bajar() {

}
