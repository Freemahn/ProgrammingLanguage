cmake_minimum_required(VERSION 2.8)

project(BigInteger)

include_directories(${BigInteger_SOURCE_DIR})

add_executable(BigInteger_testing
               BigInteger_testing.cpp
               BigInteger.h
               BigInteger.cpp
               gtest/gtest-all.cc
               gtest/gtest.h
               gtest/gtest_main.cc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x -pedantic")
target_link_libraries(BigInteger_testing -lgmp -lgmpxx -lpthread)
