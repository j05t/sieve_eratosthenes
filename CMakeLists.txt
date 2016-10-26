cmake_minimum_required(VERSION 2.8.4)
project(SieveEratosthenes)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES main.c sieve.h sieve.c)
add_executable(SieveEratosthenes ${SOURCE_FILES})