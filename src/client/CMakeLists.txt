cmake_minimum_required(VERSION 3.8.2)
project(client)

set(CMAKE_CXX_STANDARD 11)

add_executable(client
    AiPlayer.cpp
    AiPlayer.h
    Board.cpp
    Board.h
    ClientPlayer.cpp
    ClientPlayer.h
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
    StackOfDiscs.h
    Symbol.h ScreenView.cpp ScreenView.h
        CommandMannager.h CommandMannager.cpp Command.h JoinCommand.cpp JoinCommand.h StartCommand.cpp StartCommand.h CloseCommand.cpp CloseCommand.h ListOfGamesCommand.cpp ListOfGamesCommand.h)
