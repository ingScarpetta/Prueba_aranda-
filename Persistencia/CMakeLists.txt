project(Persistencia)

find_package(SOCI CONFIG REQUIRED)

add_library(Persistencia  ArbolMapper.cpp ArbolMapper.h)
target_include_directories(Persistencia PUBLIC .)
target_link_libraries(Persistencia PUBLIC SOCI::soci_core SOCI::soci_empty SOCI::soci_sqlite3)
