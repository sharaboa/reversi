//
// Created by or on 26/12/17.
//

#ifndef REVERSI_PLAYCOMMAND_H
#define REVERSI_PLAYCOMMAND_H

#include "Command.h"

class PlayCommand {
public:
    /**
     * creatin a new game flow
      * @param clientSocket1 player 1 socket
     * @param clientSocket2 player 2 socket
     */
    PlayCommand(int clientSocket1, int clientSocket2);
    /**
     * manage the flow of the game
     */
    void ClientCommunication();
    /**
     * manage each turen of the game
     * @param clientSocket1 player 1 socket
     * @param clientSocket2 player 2 socket
     * @return
     */
    bool handleTurn(int clientSocket1,int clientSocket2);
private:
    int clientSocket1, clientSocket2;
};


#endif //REVERSI_PLAYCOMMAND_H