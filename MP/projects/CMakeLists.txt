cmake_minimum_required(VERSION 3.10)  
project(projects)
set(CMAKE_CXX_STANDARD 17)
enable_testing()

add_subdirectory(lib/googletest)

add_subdirectory(dz2.sort)
add_subdirectory(dz3.Obuchalkaa)
add_subdirectory(dz4.long_number)
add_subdirectory(dz5.vector_list)
add_subdirectory(tests)