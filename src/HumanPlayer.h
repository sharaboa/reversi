//
// Or Sharabi 312530496
//Sahar levi 20340514
//

#ifndef REVERSI_HUMANPLAYER_H
#define REVERSI_HUMANPLAYER_H

#include "Player.h"
#include <string>
#include <cstring>
#include <iostream>

class HumanPlayer: public Player{
public:
    HumanPlayer(Symbol symbol1);
    virtual Disc playerLogic(Player opponentPlayer) ;
    void fromInputToDisc(char input[50]);
private:
    Disc myChoise;
};


#endif //REVERSI_HUMANPLAYER_H
