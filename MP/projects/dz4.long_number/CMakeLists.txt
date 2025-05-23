cmake_minimum_required(VERSION 3.10)
project(dz4.long_number)

set(CMAKE_CXX_STANDARD 11)
enable_testing()
set(GTEST_ROOT "/opt/homebrew/opt/googletest")

find_package(GTest REQUIRED CONFIG)

add_subdirectory(long_number)
add_subdirectory(tests)