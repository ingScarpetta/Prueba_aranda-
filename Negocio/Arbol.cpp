//
// Created by lenovo on 23/9/2020.
//

#include "Arbol.h"
#include "Nodo.h"

Negocio::Arbol::Arbol(size_t id) : _id(id),_nodoRaiz(nullptr){
}

std::shared_ptr<Negocio::Nodo> Negocio::Arbol::AgregarNodo(int valor) {

    if( _nodoRaiz == nullptr){
        _nodoRaiz = std::make_shared<Nodo>(valor);
        return _nodoRaiz;
    }
    return _nodoRaiz->AgregarNodoHijo(valor);
}

std::shared_ptr<Negocio::Nodo> Negocio::Arbol::BuscarAncestro(std::shared_ptr<Nodo> nodo1, std::shared_ptr<Nodo> nodo2) {


    return std::shared_ptr<Nodo>();
}

std::shared_ptr<Negocio::Nodo> Negocio::Arbol::BuscarNodo(int valor) {
    return std::shared_ptr<Nodo>();
}

std::shared_ptr<Negocio::Nodo> Negocio::Arbol::GetNodoRaiz() {
    return _nodoRaiz;
}
