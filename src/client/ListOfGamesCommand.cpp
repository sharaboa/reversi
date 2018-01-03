//
// Created by sahar on 27/12/17.
//

#include <cstring>
#include <sstream>
#include "ListOfGamesCommand.h"
#define MAX_COMMAND_LEN 20


ListOfGamesCommand::ListOfGamesCommand() {}

void ListOfGamesCommand::execute(string input,bool &validArg, int clientSocket) {
    int n = write(clientSocket, input.c_str(), input.length());
    if (n == -1) {
        screenView.printServerDisconect();
        exit(-1);
    }

    int numOfGames;
    n = read(clientSocket, &numOfGames, sizeof(numOfGames));
    if (n == -1) {
        screenView.printServerDisconect();
        exit(-1);
    }
    ScreenView myView;

    if(numOfGames == 0 ){
        myView.coutToScreen("No availabel game, Pls open a new one");
    } else {
        for (int j = 0; j < numOfGames; j++) {
            char i[50];
            n = read(clientSocket, &i, sizeof(i));
            if (n == -1) {
                screenView.printServerDisconect();
                exit(-1);
            }
            if(n==0) {
                screenView.printServerDisconect();
                exit(-1);
            }
            cout << endl;
            myView.coutToScreen(i);
        }
    }
    close(clientSocket);
}