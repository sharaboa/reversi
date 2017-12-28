//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_LISTGAMESCOMMAND_H
#define SERVER_LISTGAMESCOMMAND_H

#include "Command.h"


class ListGamesCommand: public Command {
    public:
        ListGamesCommand();
        virtual void execute(string arg,int clientSocket);

};


#endif //SERVER_LISTGAMESCOMMAND_H
