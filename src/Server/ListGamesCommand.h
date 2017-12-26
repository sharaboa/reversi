//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_LISTGAMESCOMMAND_H
#define SERVER_LISTGAMESCOMMAND_H

#include "Command.h"


class ListGamesCommand: public Command {
    public:
        ListGamesCommand(const vector <Game> &gamesList);
        virtual void execute(string arg,int clientSocket);

private:
    vector <Game> gamesList;

};


#endif //SERVER_LISTGAMESCOMMAND_H
