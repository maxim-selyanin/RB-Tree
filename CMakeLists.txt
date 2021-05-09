cmake_minimum_required(VERSION 3.15)
project(fine_rb)

set(CMAKE_CXX_STANDARD 17)

add_executable(fine_rb main.cpp pch.h rb_tree.h common.h color_and_state.h)