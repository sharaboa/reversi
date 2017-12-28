//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H

#include "Command.h"

class StartCommand: public Command{
public:
    StartCommand();
    virtual void execute(string arg,int clientSocket);
};



#endif //SERVER_STARTCOMMAND_H
