//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H

#include "Command.h"

class StartCommand: public Command{
public:
/**
 * command - openind a new game room
 */
    StartCommand();
    /**
     * exe the command
     * @param room the game room name
     * @param clientSocket the socket of the client that opened the room
     */
    virtual void execute(string room,int clientSocket);
};



#endif //SERVER_STARTCOMMAND_H