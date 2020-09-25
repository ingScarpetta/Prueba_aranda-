project(API)

if (WIN32)
    set(cpprestsdk_DIR "${VCPKG_ROOT_DIR}/share/cpprestsdk")
    set(unofficial-brotli_DIR "${VCPKG_ROOT_DIR}/share/unofficial-brotli")

    set(ZLIB_INCLUDE_DIR "${VCPKG_ROOT_DIR}/include")
    set(ZLIB_LIBRARY "${VCPKG_ROOT_DIR}/lib/zlib.lib")
endif()

find_package(cpprestsdk CONFIG REQUIRED)

add_library(API  ServiciosAPI.cpp ServiciosAPI.h)
target_include_directories(API PUBLIC .)
target_link_libraries(API
        cpprestsdk::cpprest
        cpprestsdk::cpprestsdk_zlib_internal
        cpprestsdk::cpprestsdk_brotli_internal)
