//
// Or Sharabi 312530496
//Sahar levi 20340514
//#include <iostream>
#include "ReversiGame.h"
#include "Menu.h"


using namespace std;



int main() {
    ReversiGame* reversiGame = new ReversiGame(4);
    Menu menu;
    menu.opponentType(reversiGame,X,O);
    delete reversiGame;
    return 0;
}