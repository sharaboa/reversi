//
// Created by or on 23/11/17.
//

#include <cstdio>
#include "Menu.h"
#include "HumanPlayer.h"
#include "ReversiGame.h"

Menu::Menu() {}

void Menu::opponentType(ReversiGame *reversiGame, Symbol black, Symbol white) {
    char choise;
    while (true) {
        cout << "choose opponent tipe:\npress h for human\npress c for computer\n";
        cin >> choise;
        if (choise == 'c' || choise == 'C' || choise == 'h' || choise == 'H') {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            reversiGame->initialize(black,white,choise);
            break;
        }

        // user didn't input a number
        cout << "choose opponent tipe:\npress h for human\npress c for computer\n" << endl;
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
}



