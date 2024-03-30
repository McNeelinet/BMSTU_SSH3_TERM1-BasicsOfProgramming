cmake_minimum_required(VERSION 3.5)

project(10_1 LANGUAGES C)

add_executable(10_1 main.c university_func.h university_func.c university_sort.h university_sort.c university_struct.h)

install(TARGETS 10_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
