//
// Or Sharabi 312530496
//Sahar levi 203405147
//


#include "ReversiGame.h"
#include "Menu.h"
#include "ClientPlayer.h"


using namespace std;



int main() {
    ReversiGame* reversiGame = new ReversiGame(4);
   Menu menu;
    menu.gameMode(reversiGame, X, O);
    delete reversiGame;
    return 0;

  /*  ClientPlayer a (X,"127.0.0.1",6886);
    ClientPlayer b (X,"127.0.0.1",6886);*/

}