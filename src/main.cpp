//Or Sharabi 312530496
#include <iostream>
#include "ReversiGame.h"
#include "Menu.h"


using namespace std;



int main() {
    ReversiGame* reversiGame = new ReversiGame(8);
    Menu menu;
    menu.opponentType(reversiGame,X,O);
    delete reversiGame;
    return 0;
}