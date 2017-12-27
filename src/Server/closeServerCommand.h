//
// Created by sahar on 27/12/17.
//

#ifndef SERVER_CLOSESERVERCOMMAND_H
#define SERVER_CLOSESERVERCOMMAND_H


#include "Command.h"
#include "CommandManager.h"

class closeServerCommand: public Command {
public:
    closeServerCommand();
    virtual void execute(string arg,int clientSocket);

private:
    CommandManager closeManager;

};


#endif //SERVER_CLOSESERVERCOMMAND_H
