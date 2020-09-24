project(Negocio)

add_library(Negocio Arbol.cpp Nodo.cpp FactoriaArbol.cpp AdministradorArboles.cpp)
target_include_directories(Negocio PUBLIC .)
