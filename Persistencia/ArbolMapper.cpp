//
// Created by lenovo on 25/9/2020.
//

#include "ArbolMapper.h"
#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>


Persistencia::ArbolMapper::ArbolMapper() {
    soci::session sql(*soci::factory_sqlite3(), "datos.db");
}

size_t Persistencia::ArbolMapper::Guardar(const std::list<int> &valores) {
    return 0;
}

std::list<int> Persistencia::ArbolMapper::Consultar(size_t id) {
    return std::list<int>();
}
