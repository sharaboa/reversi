//
// Created by sahar on 19/12/17.
//

#ifndef REVERSI_STARTCOMMAND_H
#define REVERSI_STARTCOMMAND_H


#include "Command.h"
#include "GameStruct.h"
class StartCommand :public Command {
public:
    StartCommand();
    virtual void execute(string args,int clientSocket);

};


#endif //REVERSI_STARTCOMMAND_H