//
// Created by or on 03/12/17.
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H


#include "Player.h"

class ClientPlayer : public Player {
    public:
    virtual Disc playerLogic(Player opponentPlayer);
    ClientPlayer(Symbol symbol,const char *serverIP, int serverPort);
    void connectToServer();
    int sendExercise(int arg1, char op, int arg2);
    private:
        const char *serverIP;
        int serverPort;
        int clientSocket;
};



#endif //REVERSI_CLIENT_H
