//
// Created by lenovo on 23/9/2020.
//

#include "AdministradorArboles.h"
#include "FactoriaArbol.h"

std::optional<int> Negocio::AdministradorArboles::BuscarAncestro(size_t id, int nodo1, int nodo2) {

    //aqui deberia aver un metodo que buscara el arbol por id
    std::shared_ptr<Arbol> arbol = std::make_shared<Arbol>(id);
    if (arbol == nullptr){
        ArbolNoEncontradoExcep();
        return {};
    }
    std::shared_ptr<Nodo> ptrNodo1 = arbol->BuscarNodo(nodo1);
    std::shared_ptr<Nodo> ptrNodo2 = arbol->BuscarNodo(nodo2);
    if(ptrNodo1 == nullptr || ptrNodo2 == nullptr ){
        NodoNoEncontradoExcep();
        return {};
    }
    return arbol->BuscarAncestro(ptrNodo1,ptrNodo2);
}

std::shared_ptr<Negocio::Arbol> Negocio::AdministradorArboles::CrearArbol(size_t id, const std::list<int>& valores) {

    return FactoriaArbol::GetArbol(id, valores);
}

char const *Negocio::ArbolNoEncontradoExcep::what() const {
    return "Arbol no encontrado";
}

char const *Negocio::NodoNoEncontradoExcep::what() const {
    return "nodo no encontrado";
}
