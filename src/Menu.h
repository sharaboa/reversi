//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#ifndef REVERSI_MENU_H
#define REVERSI_MENU_H

#include <iostream>
#include <limits>
#include "ReversiGame.h"

using namespace std;


class Menu {
public:
    Menu();
    void opponentType(ReversiGame *reversiGame, Symbol black, Symbol white);
};


#endif //REVERSI_MENU_H
