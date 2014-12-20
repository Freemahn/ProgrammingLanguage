cmake_minimum_required(VERSION 2.8)
project(DFS)

include_directories(${DFS_SOURCE_DIR})

add_executable(DFS_testing
               DFS_testing.cpp
               Graph.h
               gtest/gtest-all.cc
               gtest/gtest.h
               gtest/gtest_main.cc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x -pedantic")
target_link_libraries(DFS_testing -lgmp -lgmpxx -lpthread)
