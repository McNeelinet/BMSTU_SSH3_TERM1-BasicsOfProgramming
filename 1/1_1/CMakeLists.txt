cmake_minimum_required(VERSION 3.5)

project(1_1 LANGUAGES C)

add_executable(1_1 main.c)

install(TARGETS 1_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
