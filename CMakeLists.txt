cmake_minimum_required(VERSION 3.22)
project(cpp-logics)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp-logics main.cpp s0_basic/basic.cpp
        s1_introduction/introduction.cpp
        s2_data_structures/structures.cpp
        s3_recursion_sorts/recursion.cpp)