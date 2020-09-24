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
TEST( Prueba_nodos , NumeroDos ) {

    for (int i = 0; i < 500; i++) {
        Nodo nodo(i);
        nodo.AgregarNodoHijo(i + 1);
        EXPECT_EQ(nodo.GetValor(), i);
        EXPECT_NE(nodo.GetDerecha(), nullptr);
        if (nodo.GetDerecha() != nullptr) {
            EXPECT_EQ(nodo.GetDerecha()->GetValor(), i + 1);
        }
    }
}
TEST( Prueba_nodos , NumeroTres ) {

    for (int i = 0; i < 500; i++) {
        Nodo nodo(i);
        nodo.AgregarNodoHijo(i + 1);
        EXPECT_EQ(nodo.GetDerecha()->GetPadre()->GetValor(), i);
    }
}
TEST( Prueba_nodos , NumeroCuatro ) {

    for (int i = 500; i <= 0; i--) {
        Nodo nodo(i);
        nodo.AgregarNodoHijo(i -1);
        EXPECT_EQ(nodo.GetIzquierda()->GetValor(), i - 1);
    }
}
TEST( PruebaArboles , NumeroUno) {

    Arbol arbolb(1);
    arbolb.AgregarNodo(2);
    EXPECT_EQ(arbolb.GetNodoRaiz()->GetPadre(), nullptr);
}
TEST( PruebaArboles , NumeroDos) {

    Arbol arbolb(2);
    std::shared_ptr<Nodo> nodo = arbolb.AgregarNodo(1);
    nodo = arbolb.AgregarNodo(2);
    nodo = arbolb.AgregarNodo(3);
    nodo = arbolb.AgregarNodo(4);

    EXPECT_EQ(arbolb.BuscarNodo(3)->GetPadre()->GetValor(),2);
}
TEST( PruebaArboles , NumeroTres) {

    Arbol arbolb(3);
    std::shared_ptr<Nodo> nodo  = arbolb.AgregarNodo(1);
    arbolb.AgregarNodo(2);
    std::shared_ptr<Nodo> nodo1 = arbolb.AgregarNodo(3);
    std::shared_ptr<Nodo> nodo2 = arbolb.AgregarNodo(4);
    EXPECT_EQ(arbolb.BuscarAncestro(nodo1,nodo2)->GetValor(),3);
}
TEST( PruebaArboles , NumeroCuatro) {

    Arbol arbolb(4);
    std::shared_ptr<Nodo> nodo  = arbolb.AgregarNodo(5);
    arbolb.AgregarNodo(3);
    std::shared_ptr<Nodo> nodo1 = arbolb.AgregarNodo(4);
    std::shared_ptr<Nodo> nodo2 = arbolb.AgregarNodo(2);
    EXPECT_EQ(arbolb.BuscarAncestro(nodo1,nodo2)->GetValor(),3);
}