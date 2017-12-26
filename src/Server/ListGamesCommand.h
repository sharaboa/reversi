//
// Created by sahar on 19/12/17.
//

#ifndef REVERSI_LISTGAMESCOMMAND_H
#define REVERSI_LISTGAMESCOMMAND_H


#include "Command.h"

class ListGamesCommand: public Command {
public:
    ListGamesCommand(vector <Game> gamesList);
    virtual void execute(string arg,int clientSocket);
};


#endif //REVERSI_LISTGAMESCOMMAND_H