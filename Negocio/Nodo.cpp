//
// Created by lenovo on 23/9/2020.
//

#include <iostream>

#include "Nodo.h"

Negocio::Nodo::Nodo(int valor)
    : _derecha  (nullptr), _izquierda ( nullptr),
    _padre (nullptr), _valor(valor){
}

std::shared_ptr<Negocio::Nodo> Negocio::Nodo::AgregarNodoHijo(int valor) {
    // Se construye por comparación de valor donde los menores van a la izquierda y los mayores a la derecha
    if(valor < _valor){
        if(_izquierda == nullptr)
        {
            _izquierda = std::make_shared<Nodo>(valor);
            _izquierda->_padre = this;
            return _izquierda;
        }
        else
        {
            return _izquierda->AgregarNodoHijo(valor);
        }
    }
    else{
        if(valor > _valor) {
            if (_derecha == nullptr) {
                _derecha = std::make_shared<Nodo>(valor);
                _derecha->_padre = this;
                return _derecha;
            } else {
                return _derecha->AgregarNodoHijo(valor);
            }
        }
    }

    return nullptr;
}

int Negocio::Nodo::GetValor() const {
    return _valor;
}

Negocio::Nodo* Negocio::Nodo::GetPadre() {
    return _padre;
}

std::shared_ptr<Negocio::Nodo> Negocio::Nodo::GetDerecha() {
    return _derecha;
}

std::shared_ptr<Negocio::Nodo> Negocio::Nodo::GetIzquierda() {
    return _izquierda;
}
