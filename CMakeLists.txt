cmake_minimum_required(VERSION 3.8)
project(reversi)
add_subdirectory(ReversiTest)
set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES
        src/AiPlayer.cpp
        src/AiPlayer.h
        src/Board.cpp
        src/Board.h
        src/Disc.cpp
        src/Disc.h
        src/GameLogic.cpp
        src/GameLogic.h
        src/HumanPlayer.cpp
        src/HumanPlayer.h
        src/main.cpp
        src/Menu.cpp
        src/Menu.h
        src/Player.cpp
        src/Player.h
        src/ReversiGame.cpp
        src/ReversiGame.h
        src/StackOfDiscs.cpp
        src/StackOfDiscs.h
        src/Symbol.h)

add_executable(reversi ${SOURCE_FILES})