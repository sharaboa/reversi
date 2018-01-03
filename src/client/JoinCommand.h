//
// Created by sahar on 27/12/17.
//

#ifndef CLIENT_JOINCOMMAND_H
#define CLIENT_JOINCOMMAND_H

#include "Command.h"

class JoinCommand : public Command{
public:
    /**
     * joining an existing game
     */
    JoinCommand();
    /**
     * exe the player commands
     * @param input the command of the player
     * @param validArg usued as an indication to a valid arg (valid from the server side)
     * @param clientSocket the client socket (com with the server)
     */
    virtual void execute(string input,bool &validArg,int clientSocket);

};


#endif //CLIENT_JOINCOMMAND_H