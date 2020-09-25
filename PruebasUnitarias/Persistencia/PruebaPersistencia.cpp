//
// Created by lenovo on 24/9/2020.
//

#include "gtest/gtest.h"

#include "ArbolMapper.h"

using namespace Persistencia;

TEST( Prueba_Persistenncia , NumeroUno) {

    ArbolMapper db;
    std::list<int> valores{1,2,3,4};
    size_t id =  db.Guardar(valores);
    std::list<int> valoresConsul=db.Consultar(id);
    EXPECT_EQ(valores.size(),valoresConsul.size());
    if (valoresConsul.size() != valores.size()){

        return;
    }
    for( int i = 0;i <= valores.size(); i++){

        for(int j = 0;j <= valoresConsul.size(); j++){

            EXPECT_EQ(i,j);
        }

    }

}
TEST( Prueba_Persistenncia , NumeroDos) {

    ArbolMapper db;
    std::list<int> valores{1,2,8,4,3,9,10,5,11,12};
    size_t id =  db.Guardar(valores);
    std::list<int> valoresConsul=db.Consultar(id);
    EXPECT_EQ(valores.size(),valoresConsul.size());
    if (valoresConsul.size() != valores.size()){

        return;
    }
    for( int i = 0;i <= valores.size(); i++){

        for(int j = 0;j <= valoresConsul.size(); j++){

            EXPECT_EQ(i,j);
        }

    }

}