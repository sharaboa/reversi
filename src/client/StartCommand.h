//
// Created by sahar on 27/12/17.
//

#ifndef CLIENT_STARTCOMMAND_H
#define CLIENT_STARTCOMMAND_H

#include "Command.h"

class StartCommand :public Command{
public:
    /**
     * opening a new game room
     */
    StartCommand();
    /**
     * exe the player commands
     * @param input the command of the player
     * @param validArg usued as an indication to a valid arg (valid from the server side)
     * @param clientSocket the client socket (com with the server)
     */
    virtual void execute(string room,bool &validArg,int clientSocket);

};


#endif //CLIENT_STARTCOMMAND_H