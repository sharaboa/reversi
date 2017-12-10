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
    /**
     * constructor.
     * @param symbol - of disc of AiPlayer (0)
     * @param myLogic
     * @param gameBoard
     */
    AiPlayer(Symbol symbol,GameLogic myLogic,Board &gameBoard);
    /**
     * algorithem to choose disc
     * @param opponentPlayer
     * @return
     */
    virtual Disc playerLogic(Player opponentPlayer) ;
private:
    Disc myChoise;
    GameLogic myLogic;
    Board gameBoard;
};


#endif //REVERSI_AIPLAYER_H