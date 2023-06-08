cmake_minimum_required(VERSION 3.24)
project(EDA2_proyecto C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled6 sources/srcs/main+menu.c sources/headers/main+menu.h sources/srcs/usuarios.c sources/headers/usuarios.h sources/srcs/posts.c sources/headers/posts.h sources/srcs/merge_users.c sources/headers/merge_users.h sources/srcs/stack_strangers.c sources/headers/stack_strangers.h sources/srcs/dictionary_words.c sources/headers/dictionary_words.h )
