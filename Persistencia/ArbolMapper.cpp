//
// Created by lenovo on 25/9/2020.
//

#include "ArbolMapper.h"
#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>


Persistencia::ArbolMapper::ArbolMapper() : _baseDArboles(*soci::factory_sqlite3(), "datos.db"){
    InicializarBD();
}


size_t Persistencia::ArbolMapper::Guardar(const std::list<int> &valores) {

    long long idArbol;
    _baseDArboles << "INSERT INTO Arboles VALUES (NULL);";
    _baseDArboles.get_last_insert_id("Arboles", idArbol);
    for(auto dato : valores)
    {
        _baseDArboles << "INSERT INTO Nodos(valor, id_arbol) VALUES (:dato , :idArbol)",
        soci::use(dato), soci::use(idArbol);
    }

    return idArbol;

}

std::list<int> Persistencia::ArbolMapper::Consultar(size_t id) {
    soci::rowset<int> filas =( _baseDArboles.prepare << "SELECT valor FROM Nodos where id_arbol = :id ",
                                soci::use(id));
    std::list<int> valores(filas.begin(), filas.end());
    if (valores.empty()) {
        long numArbol;
        _baseDArboles << "SELECT COUNT (*) FROM Arboles WHERE id = :id",
                            soci::use(id), soci::into(numArbol);
        if (numArbol == 0) {
            throw ArbolNoEncontradoExcep();
        }
    }
    return valores;
}

void Persistencia::ArbolMapper::InicializarBD() {
    _baseDArboles << "create table IF NOT EXISTS Arboles  (id INTEGER PRIMARY KEY AUTOINCREMENT)";
    _baseDArboles << "create table IF NOT EXISTS Nodos (id  INTEGER PRIMARY KEY AUTOINCREMENT, "
                     "valor INTEGER NOT NULL , "
                     "id_arbol INTEGER NOT NULL, FOREIGN KEY(id_arbol) REFERENCES Arboles(id))";
}

char const *Persistencia::ArbolNoEncontradoExcep::what() const {
    return "Arbol no encontrado";
}

char const *Persistencia::NodoNoEncontradoExcep::what() const {
    return "nodo no encontrado";
}