//
// Or Sharabi 312530496
//Sahar levi 203405147
//


#include "ReversiGame.h"
#include "Menu.h"


using namespace std;



int main() {
    ReversiGame* reversiGame = new ReversiGame(6);
    Menu menu;
    menu.gameMode(*reversiGame, X, O);
    delete reversiGame;
    return 0;
}