
//
// Created by or on 21/12/17.
//

#ifndef REVERSI_JOINCOMMAND_H
#define REVERSI_JOINCOMMAND_H

#include "Command.h"
#include "GameStruct.h"

class JoinCommand: public Command {
public:
    JoinCommand(vector <Game> gamesList);
    virtual void execute(string arg,int clientSocket);
};


#endif //REVERSI_JOINCOMMAND_H