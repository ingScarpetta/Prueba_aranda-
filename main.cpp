#include <iostream>

#include "ServiciosAPI.h"

int main() {
    API::ServiciosAPI servidor(U("localhost"), 8080);
    servidor.Subir();
    std::cout << "Escuchando en http://localhost:8080/" << std::endl;
    while (true);
    return 0;
}
