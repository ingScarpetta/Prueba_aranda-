cmake_minimum_required(VERSION 3.17)
project(Prueba_aranda)

set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    set(VCPKG_ROOT_DIR "C:/dev/vcpkg/installed/x64-windows")
    include_directories("${VCPKG_ROOT_DIR}/include")
endif()

enable_testing()
add_subdirectory(googletest)
add_subdirectory(PruebasUnitarias)
add_subdirectory(Negocio)
add_subdirectory(Persistencia)
add_subdirectory(API)

add_executable(Prueba_aranda main.cpp)
