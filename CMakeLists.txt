cmake_minimum_required(VERSION 3.8)
project(reversi)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        AiPlayer.cpp
        AiPlayer.h
        Board.cpp
        Board.h
        Disc.cpp
        Disc.h
        GameLogic.cpp
        GameLogic.h
        HumanPlayer.cpp
        HumanPlayer.h
        main.cpp
        Menu.cpp
        Menu.h
        Player.cpp
        Player.h
        ReversiGame.cpp
        ReversiGame.h
        StackOfDiscs.cpp
        StackOfDiscs.h Symbol.h)

add_executable(reversi ${SOURCE_FILES} Symbol.h)