//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H

#include "Command.h"

class JoinCommand: public Command {
public:
    JoinCommand();
    virtual void execute(string args,int clientSocket);

};


#endif //SERVER_JOINCOMMAND_H
