cmake_minimum_required(VERSION 3.10)
project(dz5.vector_list)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED CONFIG)

add_library(containers STATIC
    ${CMAKE_CURRENT_SOURCE_DIR}/templates/templates_vector.cpp
)

target_include_directories(containers PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(test_vector tests/test_vector.cpp)
target_link_libraries(test_vector
    PRIVATE
    containers
    GTest::gtest
    GTest::gtest_main
)

add_executable(test_list tests/test_list.cpp)
target_link_libraries(test_list
    PRIVATE
    containers
    GTest::gtest
    GTest::gtest_main
)

enable_testing()
add_test(NAME test_vector COMMAND test_vector)
add_test(NAME test_list COMMAND test_list)