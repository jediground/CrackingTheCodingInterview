cmake_minimum_required(VERSION 3.3)
project(CrackingTheCodingInterview)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp 1_1.cpp 1_1.h)
add_executable(CrackingTheCodingInterview ${SOURCE_FILES})