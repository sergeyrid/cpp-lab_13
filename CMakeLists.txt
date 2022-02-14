cmake_minimum_required(VERSION 3.19)
project(lab_13)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(lab_13 src/main.cpp include/my_array.h)