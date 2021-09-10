cmake_minimum_required(VERSION 3.16)

project(MyLinkList)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
include_directories(${PROJECT_SOURCE_DIR}/header)
add_executable(Tarject ${SRC})
