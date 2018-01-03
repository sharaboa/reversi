cmake_minimum_required(VERSION 3.8)
project(Server)

set(CMAKE_CXX_STANDARD 98)

set(CMAKE_CXX_FLAGS -pthread)

set(SOURCE_FILES main.cpp Server.cpp Server.h GameStruct.h CommandManager.cpp CommandManager.h Command.h StartCommand.cpp StartCommand.h ListGamesCommand.cpp ListGamesCommand.h JoinCommand.cpp JoinCommand.h HandelClient.cpp HandelClient.h PlayCommand.h PlayCommand.cpp GamesListManager.cpp GamesListManager.h ThreadList.cpp ThreadList.h)
add_executable(Server ${SOURCE_FILES})