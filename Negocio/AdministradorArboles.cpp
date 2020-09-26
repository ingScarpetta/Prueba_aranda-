//
// Created by lenovo on 23/9/2020.
//

#include "AdministradorArboles.h"
#include "FactoriaArbol.h"
#include "ArbolMapper.h"

std::optional<int> Negocio::AdministradorArboles::BuscarAncestro(size_t id, int nodo1, int nodo2) {

    //aqui deberia aver un metodo que buscara el arbol por id
    std::list<int> valores = _mapper.Consultar(id); // TODO: Revisar arbol no existe
    std::shared_ptr<Arbol> arbol = FactoriaArbol::GetArbol(id,valores);
    std::shared_ptr<Nodo> ptrNodo1 = arbol->BuscarNodo(nodo1);
    std::shared_ptr<Nodo> ptrNodo2 = arbol->BuscarNodo(nodo2);
    if(ptrNodo1 == nullptr || ptrNodo2 == nullptr ){
        throw Persistencia::NodoNoEncontradoExcep();
    }
    return arbol->BuscarAncestro(ptrNodo1,ptrNodo2);
}

std::shared_ptr<Negocio::Arbol> Negocio::AdministradorArboles::CrearArbol( const std::list<int>& valores) {

    size_t id = _mapper.Guardar(valores);
    return FactoriaArbol::GetArbol(id, valores);
}

