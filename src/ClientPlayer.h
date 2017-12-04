//
// Created by or on 03/12/17.
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H


#include "Player.h"
#include "HumanPlayer.h"

class ClientPlayer : public HumanPlayer {
    public:
    virtual Disc playerLogic(Player opponentPlayer);
    ClientPlayer(Symbol symbol,const char *serverIP, int serverPort);
    void connectToServer();
    private:
        const char *serverIP;
        int serverPort;
        int clientSocket;
        int clientNum = 0;
};



#endif //REVERSI_CLIENT_H
