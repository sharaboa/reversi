//Or Sharabi 312530496
#include <iostream>
#include "ReversiGame.h"
#include "Menu.h"

using namespace std;

int main() {
    Menu reversi(3,'X','O');
    reversi.opponentType();
    //char winner = reversi.play();
  /*  if(winner == ' ') {
        cout << "Game Over! it's a tie " << endl;
    } else {
        cout << "Game Over! the winner is: " << winner << endl;
    }*/
}