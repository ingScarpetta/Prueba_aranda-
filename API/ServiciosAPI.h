//
// Created by lenovo on 24/9/2020.
//

#pragma once

#include <iostream>

namespace API {
    class ServiciosAPI {
    public:
        ServiciosAPI(const std::string& host, unsigned int puerto);

        void Subir();
        void Bajar();
    };
}
