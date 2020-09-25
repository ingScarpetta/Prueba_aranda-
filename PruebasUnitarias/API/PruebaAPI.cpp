//
// Created by lenovo on 24/9/2020.
//

#include "gtest/gtest.h"

#include "ServiciosAPI.h"

using namespace API;

TEST( PruebaApi , NumeroUno) {
    ServiciosAPI a ("localHost",80);
    a.Subir()
    EXPECT_EQ(1,1);
}
