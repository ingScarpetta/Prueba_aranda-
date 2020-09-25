//
// Created by lenovo on 25/9/2020.
//

#pragma once

#include <list>

namespace Persistencia {

    class ArbolMapper {
    public:
        ArbolMapper();
        size_t Guardar( const std::list<int>& valores);

        std::list<int> Consultar(size_t id);

    private:
    };
}
