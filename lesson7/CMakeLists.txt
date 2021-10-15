cmake_minimum_required(VERSION 3.20)
project(lesson7)

set(CMAKE_CXX_STANDARD 17)
include(${CMAKE_BINARY_DIR}/../build/conanbuildinfo.cmake)
include_directories(C:/.conan/7ca349/1/include)
add_executable(lesson7 main.cpp)
