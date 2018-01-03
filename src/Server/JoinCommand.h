//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H

#include "Command.h"

class JoinCommand: public Command {
public:
    /**
     * joining an existing game - command
     */
    JoinCommand();
    /**
    * exe the command
    * @param arg the arg of the command
    * @param clientSocket the socket asking to exe the commend
    */
    virtual void execute(string args,int clientSocket);
};


#endif //SERVER_JOINCOMMAND_H