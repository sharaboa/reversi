//
// Created by sahar on 27/12/17.
//

#ifndef SRC_COMMANDMANNAGER_H
#define SRC_COMMANDMANNAGER_H


#include <map>
#include "ClientPlayer.h"
#include "Command.h"
class CommandMannager {
public:
    CommandMannager();
    ~CommandMannager();
    void executeCommand(string input,int clientSocket);
    bool validCommand(string command);
private:
    map<string, Command*> commandsMap;



};


#endif //SRC_COMMANDMANNAGER_H
