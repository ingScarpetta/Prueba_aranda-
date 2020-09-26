//
// Created by lenovo on 23/9/2020.
//

#pragma  once

#include <memory>
#include <list>

#include "Arbol.h"
#include "Nodo.h"
#include "ArbolMapper.h"

namespace Negocio {

    class AdministradorArboles {
    public:
        std::optional<int> BuscarAncestro(size_t id, int nodo1, int nodo2);
        std::shared_ptr<Arbol> CrearArbol( const std::list<int>& valores);

    private:
        Persistencia::ArbolMapper _mapper;

    };

}
