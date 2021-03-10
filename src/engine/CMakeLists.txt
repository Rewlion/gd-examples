cmake_minimum_required(VERSION 3.19)

file(GLOB_RECURSE ENGINE_SOURCES "${SRC_DIR}/engine/*.cpp" "${SRC_DIR}/engine/*.cc" "${SRC_DIR}/engine/*.h")

add_library(ENGINE_LIB ${ENGINE_SOURCES})

set_target_properties(ENGINE_LIB PROPERTIES 
                        CXX_STANDARD 17
                        CXX_STANDARD_REQUIRED YES
                        CXX_EXTENSIONS NO)

target_link_libraries(ENGINE_LIB SDL2)
