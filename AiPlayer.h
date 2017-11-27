//
// Created by sahar on 26/11/17.
//

#ifndef REVERSI_AIPLAYER_H
#define REVERSI_AIPLAYER_H

#include "Player.h"
#include "GameLogic.h"

class AiPlayer: public Player{
public:
    AiPlayer(const char form, GameLogic myLogic,Board &gameBoard);
    virtual Disc playerLogic(Player opponentPlayer) ;
   // Disc calculateChoise();
private:
    Disc myChoise;
    GameLogic myLogic;
    Board gameBoard;
};


#endif //REVERSI_AIPLAYER_H
