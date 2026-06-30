cmake_minimum_required(VERSION 4.0)
project(trabalho C)

set(CMAKE_C_STANDARD 23)

add_executable(trabalho src/main.c
        src/hash.c
        src/tree.c
        src/cdr.c
        include/menu.h
        src/menu.c
)
