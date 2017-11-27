//
// Created by sahar on 23/11/17.
//

#ifndef REVERSI_HUMANPLAYER_H
#define REVERSI_HUMANPLAYER_H

#include "Player.h"
#include <string>
#include <cstring>
#include <iostream>

class HumanPlayer: public Player{
public:
    HumanPlayer(const char form);
    virtual Disc playerLogic(Player opponentPlayer);
    void fromInputToDisc(char input[50]);
private:
    Disc myChoise;
};


#endif //REVERSI_HUMANPLAYER_H
