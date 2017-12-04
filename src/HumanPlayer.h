//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#ifndef REVERSI_HUMANPLAYER_H
#define REVERSI_HUMANPLAYER_H

#include "Player.h"
#include <string>
#include <cstring>
#include <iostream>

class HumanPlayer: public Player{
public:
    /**
     * constructor.
     * @param symbol - symbol of player X or O
     */
    HumanPlayer(Symbol symbol);
    /**
     * ask the player choose disc and checks if legal
     * @param opponentPlayer - opponent player
     * @return - chosen disc
     */
    virtual Disc playerLogic(Player opponentPlayer);
    /**
     * convert input to disc
     * @param input - input of the player
     */
    void fromInputToDisc(char input[50]);

protected:
    Disc myChoise;
};


#endif //REVERSI_HUMANPLAYER_H
