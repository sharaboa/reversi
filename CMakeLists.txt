cmake_minimum_required(VERSION 3.8)
project(ex2)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h Disc.cpp Disc.h GameLogic.cpp GameLogic.h ReversiGame.cpp ReversiGame.h Player.cpp Player.h StackOfDiscs.cpp StackOfDiscs.h )
add_executable(ex2 ${SOURCE_FILES})