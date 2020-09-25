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
        EXPECT_NE(nodo.GetDerecha(), nullptr);
        if (nodo.GetDerecha() != nullptr) {
            EXPECT_NE(nodo.GetDerecha()->GetPadre(), nullptr);
            if (nodo.GetDerecha()->GetPadre() != nullptr) {
                EXPECT_EQ(nodo.GetDerecha()->GetPadre()->GetValor(), i);
            }
        }

    }
}
TEST( Prueba_nodos , NumeroCuatro ) {

    for (int i = 500; i <= 0; i--) {
        Nodo nodo(i);
        nodo.AgregarNodoHijo(i -1);
        EXPECT_NE(nodo.GetIzquierda(), nullptr);
        if (nodo.GetIzquierda() != nullptr) {
            EXPECT_EQ(nodo.GetIzquierda()->GetValor(), i - 1);
        }
    }
}
TEST( PruebaArboles , NumeroUno) {

    Arbol arbolb(1);
    arbolb.AgregarNodo(2);
    EXPECT_EQ(arbolb.GetNodoRaiz()->GetPadre(), nullptr);
}
TEST( PruebaArboles , NumeroDos) {

    Arbol arbolb(1);
    arbolb.AgregarNodo(1);
    arbolb.AgregarNodo(2);
    EXPECT_EQ(arbolb.GetNodoRaiz()->GetPadre(), nullptr);
    EXPECT_NE(arbolb.GetNodoRaiz()->GetDerecha(), nullptr);
    if(arbolb.GetNodoRaiz()->GetDerecha() != nullptr){
        EXPECT_EQ(arbolb.GetNodoRaiz()->GetDerecha()->GetValor(),2);
        EXPECT_EQ(arbolb.GetNodoRaiz()->GetDerecha()->GetPadre()->GetValor(),1);
    }
}
TEST( PruebaArboles , NumeroTres) {

    Arbol arbolb(2);
    arbolb.AgregarNodo(1);
    arbolb.AgregarNodo(2);
    arbolb.AgregarNodo(3);
    arbolb.AgregarNodo(4);

    EXPECT_EQ(arbolb.BuscarNodo(3)->GetPadre()->GetValor(),2);
}
TEST( PruebaArboles , Numerocuatro) {

    Arbol arbolb(2);
    arbolb.AgregarNodo(1);
    arbolb.AgregarNodo(2);
    arbolb.AgregarNodo(8);
    arbolb.AgregarNodo(4);
    arbolb.AgregarNodo(3);
    arbolb.AgregarNodo(9);
    arbolb.AgregarNodo(10);
    arbolb.AgregarNodo(5);
    arbolb.AgregarNodo(11);
    arbolb.AgregarNodo(12);
    auto nodoBus =arbolb.BuscarNodo(3);
    EXPECT_NE(nodoBus, nullptr);
    if(nodoBus != nullptr) {
        EXPECT_EQ(nodoBus->GetPadre()->GetValor(), 4);
    }
}
TEST( PruebaArboles , NumeroCinco) {

    Arbol arbolb(2);
    arbolb.AgregarNodo(5);
    arbolb.AgregarNodo(4);
    arbolb.AgregarNodo(3);
    arbolb.AgregarNodo(2);

    EXPECT_EQ(arbolb.BuscarNodo(3)->GetPadre()->GetValor(),4);
}
TEST( PruebaArboles , NumeroSeis) {

    Arbol arbolb(2);
    arbolb.AgregarNodo(5);
    arbolb.AgregarNodo(4);
    arbolb.AgregarNodo(3);
    arbolb.AgregarNodo(2);

    EXPECT_EQ(arbolb.BuscarNodo(6), nullptr);
}
TEST( PruebaArboles , NumeroSiete) {

    Arbol arbolb(3);
    std::shared_ptr<Nodo> nodo  = arbolb.AgregarNodo(1);
    arbolb.AgregarNodo(2);
    std::shared_ptr<Nodo> nodo1 = arbolb.AgregarNodo(3);
    std::shared_ptr<Nodo> nodo2 = arbolb.AgregarNodo(4);
    std::optional<int> respuesta = arbolb.BuscarAncestro(nodo1,nodo2);
    EXPECT_EQ(static_cast<bool>(respuesta), true);
    if (respuesta)
        EXPECT_EQ(*arbolb.BuscarAncestro(nodo1,nodo2),3);
}
TEST( PruebaArboles , NumeroOcho) {

    Arbol arbolb(4);
    std::shared_ptr<Nodo> nodo  = arbolb.AgregarNodo(5);
    arbolb.AgregarNodo(3);
    std::shared_ptr<Nodo> nodo1 = arbolb.AgregarNodo(4);
    std::shared_ptr<Nodo> nodo2 = arbolb.AgregarNodo(2);
    std::optional<int> respuesta = arbolb.BuscarAncestro(nodo1,nodo2);
    EXPECT_EQ(static_cast<bool>(respuesta), true);
    if (respuesta)
        EXPECT_EQ(*arbolb.BuscarAncestro(nodo1,nodo2),3);
}

TEST( PruebaFactoria , NumeroUno) {

    std::shared_ptr<Arbol> arbol = FactoriaArbol::GetArbol(2,{1,2,3,4,5,6});
    EXPECT_EQ(arbol->GetNodoRaiz()->GetValor(),1);
}
TEST( PruebaFactoria , NumeroDos) {

    std::shared_ptr<Arbol> arbol = FactoriaArbol::GetArbol(2,{1,2,3,4,5,6});
    EXPECT_EQ(arbol->BuscarNodo(5)->GetPadre()->GetValor(),4);
}
TEST( PruebaFactoria , NumeroTres) {

    std::shared_ptr<Arbol> arbol = FactoriaArbol::GetArbol(2,{1,2,8,4,3,9,10,5,11,12});
    EXPECT_EQ(*arbol->BuscarAncestro(arbol->BuscarNodo(3),arbol->BuscarNodo(12)),8);
}
TEST( PruebaFactoria , NumeroCuatro) {

    std::shared_ptr<Arbol> arbol = FactoriaArbol::GetArbol(2,{5,3,4,2});

    EXPECT_EQ(*arbol->BuscarAncestro(arbol->BuscarNodo(4),arbol->BuscarNodo(2)),3);
}
TEST( PruebaAdministrador , NumeroUno) {

    AdministradorArboles administrador;
    std::shared_ptr<Arbol> arbol = administrador.CrearArbol(2,{5,3,4,2});

    EXPECT_EQ(*arbol->BuscarAncestro(arbol->BuscarNodo(4),arbol->BuscarNodo(2)),3);
}
TEST( PruebaAdministrador , NumeroDos) {

    AdministradorArboles administrador;
    EXPECT_EQ(administrador.BuscarAncestro(1,4,2),3);
}