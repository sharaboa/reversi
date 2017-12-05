//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <cstdio>
#include "Menu.h"
#include "HumanPlayer.h"
#include "ReversiGame.h"

Menu::Menu() {}

void Menu::gameMode(ReversiGame *reversiGame, Symbol black, Symbol white) {
    char choise;
    while (true) {
        cout << "choose opponent type:\npress h for human\npress c for computer\n";
        cin >> choise;
        if (choise == '1' || choise == '1' || choise == 'h' || choise == 'H') {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            reversiGame->manage(black, white, choise);
            break;
        }
        // user didn't input a number
        cout << "choose opponent type:\npress h for human\npress c for computer\n" << endl;
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
}