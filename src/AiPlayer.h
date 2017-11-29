//
// Or Sharabi 312530496
//Sahar levi 203405147
//
#ifndef REVERSI_AIPLAYER_H
#define REVERSI_AIPLAYER_H

#include "Player.h"
#include "GameLogic.h"

class AiPlayer: public Player{
public:
    AiPlayer(Symbol symbol, GameLogic myLogic,Board &gameBoard);
    virtual Disc playerLogic(Player opponentPlayer) ;
private:
    Disc myChoise;
    GameLogic myLogic;
    Board gameBoard;
};


#endif //REVERSI_AIPLAYER_H
