//
// Created by sahar on 26/12/17.
//

#include "ListGamesCommand.h"

ListGamesCommand::ListGamesCommand() {}
void ListGamesCommand::execute(string arg, int clientSocket){
    vector <string> availableGame;
    for (int i = 0;i<gamesList->getGamesList().size();i++)
        if(!(gamesList->getGamesList().at(i).oSocket))
            availableGame.push_back(gamesList->getGamesList().at(i).gameName);
    int n = write(clientSocket, &availableGame, sizeof(availableGame));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
    }
}