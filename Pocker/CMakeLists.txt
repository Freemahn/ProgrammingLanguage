cmake_minimum_required(VERSION 2.8.4)
project(POCKER)
INCLUDE_DIRECTORIES(${POCKER_SOURCE_DIR})


add_executable(poker
              main.cpp
              player/player.h
              pockerController/pockerOn.h
              pockerController/pockerOn.cpp
              cards/cards.h cards/cards.cpp
              player/playerHuman.h player/playerHuman.cpp
              board/board.h board/board.cpp
)


 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -g -std=c++0x")


target_link_libraries(poker)