//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <cstdio>
#include "Menu.h"


Menu::Menu() {}

void Menu::gameMode(ReversiGame &reversiGame, Symbol black, Symbol white) {
    char choice;
    cout << "\nWelcome to Reversi\n\n";

    while (true) {
        cout << "choose an opponent type:\n1. a human local player\n2. an AI player\n3. a remote player\n";
        cin >> choice;
        if (choice == '1' || choice == '2' || choice == '3') {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
            switch (choice) {
                case '1': {
                    reversiGame.manageHuman(black, white);
                    break;
                }
                case '2': {
                    reversiGame.manageAi(black,white);
                    break;
                }
                case '3': {
                    reversiGame.manageRemoteGame(black,white);
                    break;
                }
            }
            break;
        }
        // user didn't input correct choice
        cout << "Wrong Choice! choose again\n" << endl;
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
}