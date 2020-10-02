cmake_minimum_required(VERSION 3.17)
project(objective_string C)

set(CMAKE_C_STANDARD 90)

add_library(ostring SHARED ostring.c ostring.h)
