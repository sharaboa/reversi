//
// Created by or on 23/11/17.
//

#include <cstdio>
#include "Menu.h"
#include "HumanPlayer.h"
#include "ReversiGame.h"

Menu::Menu(const int size,const char b,const char w):size(size),black(b),white(w) {}

char Menu::opponentType() {
    HumanPlayer me(black);
    char choise = 0;
    do {
        cout << "choose opponent tipe:\npress h for human\npress c for computer\n";
        scanf(" %c",&choise);
        if (!cin.fail()) {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cin.clear();
    } while(choise != 'c' && choise != 'C' && choise != 'h' && choise != 'H');

    switch (choise) {
            /*case 'c' || 'C':
                AiPlayer opponentAiPlayer(white);
                GameLogic gameLogic(size, me, opponentAiPlayer);
                reversiGame.play();*/
            case 'h': case 'H': {
                HumanPlayer opponentHumanPlayer(white);
                ReversiGame reversiGame(size, me, opponentHumanPlayer);
                reversiGame.play();
                break;
            }
        }
    }