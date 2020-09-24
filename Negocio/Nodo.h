//
// Created by lenovo on 23/9/2020.
//

#pragma once

#include <memory>

namespace Negocio {
    class Nodo {

    public:

        Nodo (int valor);

        void AgregarNodoHijo(int valor);

        int GetValor();

    private:

        std::shared_ptr<Nodo>  _derecha;
        std::shared_ptr<Nodo> _izquierda;
        std::shared_ptr<Nodo>  _padre;
        int _valor;
    };
}
