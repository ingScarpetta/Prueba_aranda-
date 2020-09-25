set(Self PruebaAPI)

add_executable(${Self} PruebaAPI.cpp)
target_link_libraries(${Self} gtest_main API)
add_custom_command(TARGET ${Self} COMMENT "Prueba unitaria de API" POST_BUILD COMMAND ${Self})
