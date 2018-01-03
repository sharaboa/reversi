//
// Created by sahar on 27/12/17.
//

#ifndef CLIENT_LISTOFGAMESCOMMAND_H
#define CLIENT_LISTOFGAMESCOMMAND_H

#include <vector>
#include "Command.h"

class ListOfGamesCommand: public Command {
public:
    /*
     * getting a list of the current open rooms in the server
     */
    ListOfGamesCommand();
    /**
      * exe the player commands
      * @param input the command of the player
      * @param validArg usued as an indication to a valid arg (valid from the server side)
      * @param clientSocket the client socket (com with the server)
      */
    virtual void execute(string input,bool &validArg,int clientSocket);

};


#endif //CLIENT_LISTOFGAMESCOMMAND_H