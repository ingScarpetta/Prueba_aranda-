set(Self PruebaNegocio)

add_executable(${Self} PruebaNegocio.cpp)
target_link_libraries(${Self} gtest_main Negocio)
add_custom_command(TARGET ${Self} COMMENT "Prueba unitaria de Arboles" POST_BUILD COMMAND ${Self})
