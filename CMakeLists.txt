cmake_minimum_required(VERSION 3.20)
project(MCO3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(MCO3
        bst.h
        main.c
        sstring.h)
