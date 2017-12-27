//
// Created by sahar on 27/12/17.
//

#include <cstring>
#include "ListOfGamesCommand.h"
#include "ScreenView.h"

ListOfGamesCommand::ListOfGamesCommand() {}

void ListOfGamesCommand::execute(string input, int clientSocket) {
    int n = write(clientSocket, &input, sizeof(input));
    if (n == -1) {
        throw "Error writing arg1to socket";
    }


    /////////////////   if not use int
    n = read(clientSocket, &listGame, sizeof(listGame));
    if (n == -1) {
        throw "Error writing arg1to socket";
    }

    ScreenView myView;
    for (int i = 0; i <listGame.size() ; ++i) {
        myView.coutToScreen(listGame.at(i));

    }
}
