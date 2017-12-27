//
// Created by sahar on 27/12/17.
//

#ifndef CLIENT_CLOSECOMMAND_H
#define CLIENT_CLOSECOMMAND_H

#include "Command.h"
class CloseCommand: public Command{
public:
    CloseCommand();
    virtual void execute(string input,int clientSocket);
};


#endif //CLIENT_CLOSECOMMAND_H
