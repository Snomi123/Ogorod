cmake_minimum_required(VERSION 3.10)

project(dz2.sort)

add_library(${PROJECT_NAME} sort.cpp)

add_executable(MP main.cpp)

target_link_libraries(MP dz2.sort)

target_include_directories(MP PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})