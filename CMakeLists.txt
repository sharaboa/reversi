cmake_minimum_required(VERSION 3.8)
project(reversi)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES
        Board.cpp
        Board.h
        Disc.cpp
        Disc.h
        GameLogic.cpp
        GameLogic.h
        main.cpp
        Player.cpp
        Player.h
        ReversiGame.cpp
        ReversiGame.h
        StackOfDiscs.cpp
        StackOfDiscs.h)

add_executable(reversi ${SOURCE_FILES})