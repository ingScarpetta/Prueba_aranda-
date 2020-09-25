//
// Created by lenovo on 23/9/2020.
//

#pragma  once

#include <memory>
#include <list>

#include "Arbol.h"
#include "Nodo.h"

namespace Negocio {

    struct ArbolNoEncontradoExcep : std::exception {
        char const* what() const override;
    };
    struct NodoNoEncontradoExcep : std::exception {
        char const* what() const override;
    };

    class AdministradorArboles {
    public:
        std::optional<int> BuscarAncestro(size_t id, int nodo1, int nodo2);
        std::shared_ptr<Arbol> CrearArbol(size_t id, const std::list<int>& valores);

    };

}
