//
// Created by or on 23/11/17.
//

#include "Menu.h"

Menu::Menu(const int size,const char b,const char w):size(size),black(b),white(w) {}

char Menu::opponentType() {
    HumanPlayer me(black);
    char opponantTypeChoise;
    while(true) {
        cout << "choose opponent tipe:\npress h for human\n(c)press c for computer\n";
        cin >> opponantTypeChoise;
        switch (opponantTypeChoise) {
            case 'h' || 'H':
                AiPlayer opponentAiPlayer(white);
                GameLogic gameLogic(size, me, aiPlayer);
            case 'c' || 'C':
                HumanPlayer opponentHumanPlayer(white);
                GameLogic gameLogic(size, me, aiPlayer);
            default:
                cin.ignore();
                cin.clear();
                "choose opponent tipe:\npress h for human\n(c)press c for computer\n";
        }
    }
}