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
    /**
     * this func creats the menu allowing you to choose the game mode
     * @param reversiGame is the game manager
     * @param black the first player of the game. player symbol is X
     * @param white the second player of the game. player symbol is O
     */
    void gameMode(ReversiGame &reversiGame, Symbol black, Symbol white);
};


#endif //REVERSI_MENU_H