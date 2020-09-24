//
// Created by lenovo on 23/9/2020.
//

#pragma once

#include <memory>

namespace Negocio {
    class Nodo {

    public:

        Nodo (int valor);

        std::shared_ptr<Nodo> AgregarNodoHijo(int valor);

        int GetValor() const;
        Nodo * GetPadre();
        std::shared_ptr<Nodo> GetDerecha();
        std::shared_ptr<Nodo> GetIzquierda();

    private:

        std::shared_ptr<Nodo>  _derecha;
        std::shared_ptr<Nodo> _izquierda;
        Nodo * _padre; // no puede ser de tipo shared_ptr
        int _valor;
    };
}
