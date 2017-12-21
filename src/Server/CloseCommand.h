//
// Created by or on 21/12/17.
//

#ifndef REVERSI_CLOSECOMMAND_H
#define REVERSI_CLOSECOMMAND_H


#include "Command.h"

class CloseCommand: public Command {
public:
    CloseCommand(vector <Game> gamesList);
    virtual void execute(string args,int clientSocket);
};


#endif //REVERSI_CLOSECOMMAND_H
