//
// Created by or on 19/12/17.
//

#ifndef REVERSI_COMMANDSMANAGER_H
#define REVERSI_COMMANDSMANAGER_H


#include <map>
#include "Command.h"
class CommandsManager {

public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(string input,int clientSocket);

private:
    map<string, Command *> commandsMap;
    vector <Game> gamesList;
};


#endif //REVERSI_COMMANDSMANAGER_H