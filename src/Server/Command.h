//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H


#include <vector>
#include "GameStruct.h"
#include <unistd.h>

class Command {
    public:
        virtual void execute(string arg, int clientSocket) = 0;
        virtual ~Command() {}
    protected:
        vector <Game> gamesList;
};


#endif //SERVER_COMMAND_H
