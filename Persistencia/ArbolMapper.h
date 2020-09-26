//
// Created by lenovo on 25/9/2020.
//

#pragma once

#include <list>
#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>

namespace Persistencia {

    struct ArbolNoEncontradoExcep : std::exception {
        char const* what() const override;
    };
    struct NodoNoEncontradoExcep : std::exception {
        char const* what() const override;
    };

    class ArbolMapper {
    public:
        ArbolMapper();
        size_t Guardar( const std::list<int>& valores);

        std::list<int> Consultar(size_t id);

    private:
        soci::session  _baseDArboles;
/* NO USAR soci::session sql("sqlite3", "db=db.sqlite timeout=2 shared_cache=true");
 * . Carga dinamicamente propenso a errores */

        void InicializarBD();

};
}
