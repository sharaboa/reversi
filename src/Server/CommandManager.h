//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_COMMANDMANAGER_H
#define SERVER_COMMANDMANAGER_H

#include <map>
#include "Command.h"

class CommandManager {
    public:
         CommandManager();
        ~CommandManager();
        void executeCommand(string input,int clientSocket);
    private:
        map<string, Command*> commandsMap;
        //vector <Game> gamesList;


};


#endif //SERVER_COMMANDMANAGER_H
