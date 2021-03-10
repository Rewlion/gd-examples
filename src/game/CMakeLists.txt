cmake_minimum_required(VERSION 3.19)

file(GLOB_RECURSE GAME_SOURCES "${SRC_DIR}/game/*.cpp" "${SRC_DIR}/game/*.cc" "${SRC_DIR}/game/*.h")

add_executable(GAME_EXE ${GAME_SOURCES})

set_target_properties(GAME_EXE PROPERTIES 
                        CXX_STANDARD 17
                        CXX_STANDARD_REQUIRED YES
                        CXX_EXTENSIONS NO
                        RUNTIME_OUTPUT_DIRECTORY "${RUNTIME_OUTPUT_DIRECTORY}"
                        VS_DEBUGGER_WORKING_DIRECTORY "${RUNTIME_OUTPUT_DIRECTORY}/Debug")

target_link_libraries(GAME_EXE ENGINE_LIB)
