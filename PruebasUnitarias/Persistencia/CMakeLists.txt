set(Self PruebaPersistencia)

add_executable(${Self} PruebaPersistencia.cpp)
target_link_libraries(${Self} gtest_main Persistencia)
add_custom_command(TARGET ${Self} COMMENT "Prueba unitaria de Persistencia" POST_BUILD COMMAND ${Self})
