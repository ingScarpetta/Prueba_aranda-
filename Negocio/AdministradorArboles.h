//
// Created by lenovo on 23/9/2020.
//

#pragma  once

#include <memory>
#include <list>

#include "Arbol.h"
#include "Nodo.h"
namespace Negocio {

    class AdministradorArboles {
    public:
        std::shared_ptr<Nodo> BuscarAncestro(size_t id, std::shared_ptr<Nodo> nodo1, std::shared_ptr<Nodo> nodo2);
        std::shared_ptr<Arbol> CrearArbol(size_t id, std::list<int> valores);

    };

}
