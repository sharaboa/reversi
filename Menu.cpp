//
// Created by or on 23/11/17.
//

#include <cstdio>
#include "Menu.h"
#include "HumanPlayer.h"
#include "ReversiGame.h"

Menu::Menu(const int size,const char b,const char w):size(size),black(b),white(w) {}

char Menu::opponentType() {
    char choise;
    while (true) {
        cout << "choose opponent tipe:\npress h for human\npress c for computer\n";
        cin >> choise;
        if (choise == 'c' || choise == 'C' || choise == 'h' || choise == 'H') {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            ReversiGame reversiGame(size,black,white,choise);
            reversiGame.play();
            break;
        }

        // user didn't input a number
        cout << "choose opponent tipe:\npress h for human\npress c for computer\n" << endl;
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
}


