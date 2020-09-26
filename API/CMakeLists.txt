project(API)

find_package(cpprestsdk CONFIG REQUIRED)

add_library(API  ServiciosAPI.cpp ServiciosAPI.h)
target_include_directories(API PUBLIC .)
target_link_libraries(API
        cpprestsdk::cpprest
        cpprestsdk::cpprestsdk_zlib_internal
        cpprestsdk::cpprestsdk_brotli_internal)
