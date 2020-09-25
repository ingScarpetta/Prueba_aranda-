set(Self PruebaEjemplo)

ADD_SUBDIRECTORY(Negocio)
ADD_SUBDIRECTORY(API)

add_executable(${Self} prueba_ejemplo.cpp)
target_link_libraries(${Self} gtest_main)
add_custom_command(TARGET ${Self} COMMENT "Prueba unitaria de ejemplo" POST_BUILD COMMAND ${Self})
