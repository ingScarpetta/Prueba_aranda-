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
        std::shared_ptr<Arbol> GetArbol(size_t id, std::list<int> valores);

    };

}
