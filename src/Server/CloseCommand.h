//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_CLOSECOMMAND_H
#define SERVER_CLOSECOMMAND_H

#include "Command.h"

class CloseCommand: public Command {
public:
    CloseCommand(const vector <Game> &gamesList);
    virtual void execute(string arg,int clientSocket);

private:
    vector<Game> gamesList;
};


#endif //SERVER_CLOSECOMMAND_H
