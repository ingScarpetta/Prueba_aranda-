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
    // web::json::value entrada_json;
    // entrada_json[U("id")] = 12;
    /*
    entrada_json[U("float")] = 12.45;
    entrada_json[U("arreglo")] = web::json::value::array({2, 3, 4, 5});
    utility::string_t nombre(U("Laura mi nombre"));
    entrada_json[U("nombre")] = web::json::value(nombre,
                                                 false);
    std::wcout << entrada_json << std::endl;
     */
    EXPECT_EQ(1,1);
}
