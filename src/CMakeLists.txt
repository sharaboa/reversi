cmake_minimum_required(VERSION 3.8)
project(reversi)
add_subdirectory(ReversiTest)
set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES
        client/AiPlayer.cpp
        client/AiPlayer.h
        client/Board.cpp
        client/Board.h
        client/Disc.cpp
        client/Disc.h
        client/GameLogic.cpp
        client/GameLogic.h
        client/HumanPlayer.cpp
        client/HumanPlayer.h
        client/main.cpp
        client/Menu.cpp
        client/Menu.h
        client/Player.cpp
        client/Player.h
        client/ReversiGame.cpp
        client/ReversiGame.h
        client/StackOfDiscs.cpp
        client/StackOfDiscs.h
        client/Symbol.h client/ClientPlayer.cpp client/ClientPlayer.h)

add_executable(reversi ${SOURCE_FILES})