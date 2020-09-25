//
// Created by lenovo on 23/9/2020.
//

#pragma once

#include <list>
#include <memory>

#include "Arbol.h"

namespace Negocio {

    class FactoriaArbol {

    public:
        FactoriaArbol();
        static std::shared_ptr<Arbol> GetArbol(size_t id, const std::list<int>&  valores);

    };

}
