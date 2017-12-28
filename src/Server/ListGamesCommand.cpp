//
// Created by sahar on 26/12/17.
//

#include "ListGamesCommand.h"

ListGamesCommand::ListGamesCommand() {}
void ListGamesCommand::execute(string arg, int clientSocket){
    vector <string> availableGame;
    for (int i = 0;i<this->getGamesList().size();i++)
        if(!(this->getGamesList().at(i).oSocket))
            availableGame.push_back(this->getGamesList().at(i).gameName);
    int n = write(clientSocket, &availableGame, sizeof(availableGame));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
    }
}