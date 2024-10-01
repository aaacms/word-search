cmake_minimum_required(VERSION 3.29)
project(word_search)

set(CMAKE_CXX_STANDARD 20)

add_executable(word_search main.c
        busca.c
        busca.h
        matriz.c
        matriz.h
        matriz.c
)
