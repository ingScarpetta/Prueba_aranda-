//
// Created by lenovo on 25/9/2020.
//

#pragma once

#include <list>
#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>

namespace Persistencia {

    class ArbolMapper {
    public:
        ArbolMapper();
        size_t Guardar( const std::list<int>& valores);

        std::list<int> Consultar(size_t id);

    private:
/* NO USAR soci::session sql("sqlite3", "db=db.sqlite timeout=2 shared_cache=true");
 * . Carga dinamicamente propenso a errores */
};
}
