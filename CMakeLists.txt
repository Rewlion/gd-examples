cmake_minimum_required(VERSION 3.19)

project(gd-examples VERSION 0.1
        DESCRIPTION "<=*_*=>"
        LANGUAGES CXX)


find_package(Vulkan)

set(RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(DEP_DIR "${CMAKE_SOURCE_DIR}/thirdparty")
set(SDL2_DEP_DIR "${DEP_DIR}/SDL2")

file(COPY ${SDL2_DEP_DIR}/x64/SDL2.dll
     DESTINATION ${RUNTIME_OUTPUT_DIRECTORY}/Debug)

file(COPY ${SDL2_DEP_DIR}/x64/SDL2.dll
     DESTINATION ${RUNTIME_OUTPUT_DIRECTORY}/Release)


link_directories("${SDL2_DEP_DIR}/x64")

include_directories(
    "${DEP_DIR}"
)

add_subdirectory("${SRC_DIR}/game")
