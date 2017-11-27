//Or Sharabi 312530496
#include <iostream>
#include "ReversiGame.h"
#include "Menu.h"

using namespace std;

int main() {
    ReversiGame reversiGame(4);
    Menu menu;
    menu.opponentType(reversiGame,'X','O');
}