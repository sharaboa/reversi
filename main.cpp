//Or Sharabi 312530496
#include <iostream>
#include "ReversiGame.h"

using namespace std;

int main() {
    ReversiGame reversi(6,'X','O');
    char winner = reversi.play();
    if(winner == ' ') {
        cout << "Game Over! it's a tie " << endl;
    } else {
        cout << "Game Over! the winner is: " << winner << endl;
    }
}