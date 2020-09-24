//
// Created by lenovo on 23/9/2020.
//

#include "gtest/gtest.h"

#include "Arbol.h"
#include "Nodo.h"
#include "FactoriaArbol.h"
#include "AdministradorArboles.h"

using namespace Negocio;

TEST( Prueba_nodos , NumeroUno) {
    for (int i = 0; i < 500; i++) {
        Nodo nodo(i);
        EXPECT_EQ(nodo.GetValor(), i);
    }
}
