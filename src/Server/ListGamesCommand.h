//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_LISTGAMESCOMMAND_H
#define SERVER_LISTGAMESCOMMAND_H

#include "Command.h"


class ListGamesCommand: public Command {
public:
    /**
     * sending the list of opened games
     */
    ListGamesCommand();
    /**
     * exe the command
     * @param arg the arg of the command
     * @param clientSocket the socket asking to exe the commend
     */
    virtual void execute(string arg,int clientSocket);

};


#endif //SERVER_LISTGAMESCOMMAND_H