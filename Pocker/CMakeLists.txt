cmake_minimum_required(VERSION 2.8)
project(Pocker)

include_directories(${Pocker_SOURCE_DIR})

add_executable(pocker_testing
               pocker_testing.cpp
                include/Card.h
               include/Exceptions.h
               include/Hand.h
               include/Rules.h
               src/Card.cpp
               src/Player.cpp
               src/Rules.cpp

               gtest/gtest-all.cc
               gtest/gtest.h
               gtest/gtest_main.cc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x -pedantic")
target_link_libraries(pocker_testing -lgmp -lgmpxx -lpthread)
