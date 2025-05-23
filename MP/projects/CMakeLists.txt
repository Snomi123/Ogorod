cmake_minimum_required(VERSION 3.31.6)
project(projects)
set(CMAKE_CXX_STANDARD 11)
enable_testing()

add_subdirectory(lib/googletest)

add_subdirectory(dz2.sort)
add_subdirectory(dz3.Obuchalkaa)
add_subdirectory(long_number)
add_subdirectory(tests)