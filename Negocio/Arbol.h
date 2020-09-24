//
// Created by lenovo on 23/9/2020.
//

#pragma once

#include <memory>

#include "Nodo.h"

namespace Negocio {
    class Arbol {

    public:
        Arbol(size_t id);

        std::shared_ptr<Nodo>AgregarNodo(int valor);

        std::shared_ptr<Nodo> BuscarAncestro(std::shared_ptr<Nodo> nodo1, std::shared_ptr<Nodo> nodo2);

        std::shared_ptr<Nodo> BuscarNodo(int valor);

        std::shared_ptr<Nodo> GetNodoRaiz();

    private:

        std::shared_ptr<Nodo> _nodoRaiz;
        size_t _id;

    };
}
