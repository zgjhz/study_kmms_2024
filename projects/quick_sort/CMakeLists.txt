cmake_minimum_required(VERSION 3.26)
project(quick_sort)

set(CMAKE_CXX_STANDARD 17)

add_executable(quick_sort main.cpp
        quick_sort.cpp
        quick_sort.hpp)
