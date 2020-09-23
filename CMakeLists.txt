cmake_minimum_required(VERSION 3.17)
project(Prueba_aranda)

set(CMAKE_CXX_STANDARD 20)

enable_testing()
add_subdirectory(googletest)
add_subdirectory(PruebasUnitarias)

add_executable(Prueba_aranda main.cpp)
