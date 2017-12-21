cmake_minimum_required(VERSION 3.8)
project(server)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Server.cpp Server.h Command.h CommandsManager.cpp CommandsManager.h StartCommand.cpp StartCommand.h ListGamesCommand.cpp ListGamesCommand.h GameStruct.h JoinCommand.cpp JoinCommand.h PlayCommand.cpp PlayCommand.h CloseCommand.cpp CloseCommand.h)
add_executable(server ${SOURCE_FILES})