//
// Created by lenovo on 23/9/2020.
//

#include "FactoriaArbol.h"

Negocio::FactoriaArbol::FactoriaArbol() {

}

std::shared_ptr<Negocio::Arbol> Negocio::FactoriaArbol::GetArbol(size_t id, const std::list<int>& valores) {
    std::shared_ptr<Arbol> arbol = std::make_shared<Arbol>(id);
    //
    for (auto i : valores) {
        arbol->AgregarNodo(i);
    }
    return arbol;
}
