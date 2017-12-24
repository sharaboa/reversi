//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <cstdio>
#include "Menu.h"


Menu::Menu() {}

void Menu::gameMode(ReversiGame &reversiGame, Symbol black, Symbol white) {
    char choice;
    bool goodChoice = true;
    screenView.printMenu(goodChoice);
    while (true) {
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
        goodChoice = false;
        screenView.printMenu(goodChoice);
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }
}