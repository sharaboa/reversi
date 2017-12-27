//
// Created by sahar on 27/12/17.
//

#ifndef CLIENT_JOINCOMMAND_H
#define CLIENT_JOINCOMMAND_H

#include "Command.h"

class JoinCommand : public Command{
public:
    JoinCommand();
    virtual void execute(string input,int clientSocket);

};


#endif //CLIENT_JOINCOMMAND_H
