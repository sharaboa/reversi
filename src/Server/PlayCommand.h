//
// Created by or on 21/12/17.
//

#ifndef REVERSI_PLAYCOMMAND_H
#define REVERSI_PLAYCOMMAND_H


#include "Command.h"

using namespace std;

class PlayCommand: public Command {
public:
    PlayCommand(vector <Game> gamesList);
    virtual void execute(string args,int clientSocket);
};
};


#endif //REVERSI_PLAYCOMMAND_H
