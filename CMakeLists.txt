cmake_minimum_required(VERSION 3.17)
project(aoc C)

set(CMAKE_C_STANDARD 99)

add_executable(aoc main.c Day1/Day1.c Day1/Day1.h Day2/Day2.c Day2/Day2.h)