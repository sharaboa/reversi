//
// Created by or on 26/12/17.
//

#ifndef REVERSI_PLAYCOMMAND_H
#define REVERSI_PLAYCOMMAND_H

#include "Command.h"

class PlayCommand {
public:
    PlayCommand(int clientSocket1, int clientSocket2);
    void ClientCommunication();
    bool handleTurn(int clientSocket1,int clientSocket2);
private:
    int clientSocket1, clientSocket2;
};


#endif //REVERSI_PLAYCOMMAND_H
