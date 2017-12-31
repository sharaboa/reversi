//
// Created by sahar on 27/12/17.
//

#ifndef CLIENT_STARTCOMMAND_H
#define CLIENT_STARTCOMMAND_H

#include "Command.h"

class StartCommand :public Command{
public:
    StartCommand();
    virtual void execute(string room,int clientSocket);

};


#endif //CLIENT_STARTCOMMAND_H
