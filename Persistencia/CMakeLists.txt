project(Persistencia)

# se debe copiar y renombrar el archivo SOCI.cmake en esa carpeta a SOCIConfig.cmake
if (WIN32)
    set(SOCI_DIR "${VCPKG_ROOT_DIR}/share/SOCI")
    include_directories("${VCPKG_ROOT_DIR}/include")
endif()

find_package(SOCI CONFIG REQUIRED)

add_library(Persistencia  ArbolMapper.cpp ArbolMapper.h)
target_include_directories(Persistencia PUBLIC .)
target_link_libraries(Persistencia PRIVATE SOCI::soci_core SOCI::soci_empty SOCI::soci_sqlite3)
