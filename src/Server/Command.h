//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H


#include <vector>
#include "GameStruct.h"
#include "GamesListManager.h"
#include <unistd.h>

class Command {
    public:
        virtual void execute(string arg, int clientSocket) = 0;
        virtual ~Command() {}
    protected:
    GamesListManager *gamesList = GamesListManager::getInstance();

};


#endif //SERVER_COMMAND_H
