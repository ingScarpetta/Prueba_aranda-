#include <iostream>

#include "ServiciosAPI.h"

int main(int argc, char* argv[]) {
    if (argc > 3) {
        std::cerr << "Se recibieron mas de dos argumentos" << std::endl;
        return 1;
    }
    if (argc == 2) {
        std::cerr << "Se recibieron solo un argumentos " << argv[1] << std::endl;
        return 1;
    }
    int puerto = 8080;
    if (argc == 3) {
        std::string argumento (argv[1]);
        if (argumento != "-p" && argumento != "--puerto") {
            std::cerr << "Argumento " << argumento << " no valido" << std::endl;
            return 1;
        }
        std::string puertoStr(argv[2]);
        std::stringstream valorEntero(puertoStr);
        valorEntero >> puerto;
        if (!valorEntero) {
            std::cerr << "Valor del puerto: " << puertoStr << " no es un entero" << std::endl;
            return 1;
        }
    }
    std::cout << "******* Prueba tecnica Aranda Software Andina ****** " << std::endl;
    std::cout << "*******              Version 1.0.0            ****** " << std::endl;
    try {
        API::ServiciosAPI servidor(U("localhost"), puerto);
        servidor.Subir();
        std::cout << "Escuchando en http://localhost:" << puerto << "/" << std::endl;
        while (true);
    }
    catch (std::exception& excepcion) {
        std::cerr << "Error " << excepcion.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Error desconocido" << std::endl;
    }
    return 1;
}
