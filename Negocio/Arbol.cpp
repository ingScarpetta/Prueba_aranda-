//
// Created by lenovo on 23/9/2020.
//

#include <map>
#include <optional>

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

std::optional<int> Negocio::Arbol::BuscarAncestro(const std::shared_ptr<Nodo>& nodo1,
                                                  const std::shared_ptr<Nodo>& nodo2) {

    // crea un conjunto de ancestros para el nodo uno
    std::map <int, bool> ancestros;
    int valor = nodo1->GetValor();
    ancestros[valor]= true;
    Nodo * nodo = nodo1->GetPadre();
    while (nodo != nullptr)// recorre el nodo de padre en padre hasta llegar al nodo raiz
    {
        ancestros[nodo->GetValor()] = true;
        nodo = nodo->GetPadre();
    }

    // mira si el nodo 2 esta dentro de los ancestros del  nodo 1
    if (ancestros.find(nodo2->GetValor()) != ancestros.end())
        return nodo2->GetValor();
    nodo =nodo2->GetPadre();
    while (nodo != nullptr)
    {
        if (ancestros.find(nodo->GetValor()) != ancestros.end())
            return nodo->GetValor();
        nodo = nodo->GetPadre();
    }

    return {};
}

std::shared_ptr<Negocio::Nodo> Negocio::Arbol::BuscarNodo(int valor) {
    if (_nodoRaiz->GetValor() == valor ){
        return _nodoRaiz;
    }
    Nodo * nodoPadre;
    std::shared_ptr<Nodo> nodo = _nodoRaiz;
    while(nodo->GetIzquierda() != nullptr){
        nodo = nodo->GetIzquierda();
        if (nodo->GetValor() == valor){
            return nodo;
        }
    }
    if(nodo != _nodoRaiz){
        nodoPadre = nodo->GetPadre();
    }
    else{
        while(nodo->GetDerecha() != nullptr) {
            nodo = nodo->GetDerecha();
            if (nodo->GetValor() == valor) {
                return nodo;
            }
        }
        nodoPadre = nodo->GetPadre();
        while(nodoPadre->GetPadre()!= nullptr ) {
            while (nodoPadre->GetIzquierda() != nullptr)
            {
                nodo=nodoPadre->GetIzquierda();
                if (nodo->GetValor() == valor){
                    return nodo;
                }
                else{
                    nodoPadre=nodoPadre->GetPadre();
                }

            }
        }
    }
    while(nodoPadre->GetPadre()!= nullptr ) {
        while (nodoPadre->GetDerecha() != nullptr) {
            nodo = nodoPadre->GetDerecha();
            if (nodo->GetValor() == valor) {
                return nodo;
            } else {
                nodoPadre = nodoPadre->GetPadre();
            }

        }
    }
    return nullptr;
}

std::shared_ptr<Negocio::Nodo> Negocio::Arbol::GetNodoRaiz() {
    return _nodoRaiz;
}
