cmake_minimum_required(VERSION 3.0)
project(tetristy VERSION 0.1.0)
set(CMAKE_C_FLAGS "-Wall -Wextra" CACHE STRING "" FORCE)

file(GLOB SOURCES src/*.c)
add_executable(tetristy ${SOURCES})

find_library(NCURSES_LIB NAMES ncurses PATHS /usr/include)
target_link_libraries(tetristy ${NCURSES_LIB})

install(TARGETS tetristy)
