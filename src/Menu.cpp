//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <cstdio>
#include "Menu.h"
#include "HumanPlayer.h"


Menu::Menu() {}

void Menu::gameMode(int size, Symbol black, Symbol white) {
    char choise;
    cout << "Welcome to Reversi\n\n";

    while (true) {
        cout << "choose an opponent type:\n1. a human local player\n2. an AI player\n3. a remote player\n";
        cin >> choise;
        if (choise == '1' || choise == '2' || choise == '3') {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            switch (choise) {
                case '1': {
                    ReversiGame reversi(size);
                    reversi.manageHuman(black, white);
                    break;
                }
                case '2': {
                    ReversiGame reversi(size);
                    reversi.manageAi(black,white);
                    break;
                }
                case '3': {
                    ReversiGame reversi(size);
                    reversi.manageRemoteGame(black,white);
                    break;
                }
            }
            break;
        }
        // user didn't input a number
        cout << "Wrong Choise! choose again\n" << endl;
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
}