cmake_minimum_required(VERSION 3.5)
project(bitmap)

set(CMAKE_CXX_STANDARD 11)
add_executable(bitmap ./test/test.cpp BitMap.h BitMap.cpp)
