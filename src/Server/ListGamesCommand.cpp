//
// Created by sahar on 19/12/17.
//

#include "ListGamesCommand.h"


ListGamesCommand::ListGamesCommand(vector <Game> gamesList) {}

void ListGamesCommand::execute(string arg, int clientSocket){
    vector <string> availableGame;
    for (int i = 0;i<gamesList.size();i++)
        if(!(gamesList.at(i).oSocket))
            availableGame.push_back(gamesList.at(i).gameName);
    int n = write(clientSocket, &availableGame, sizeof(availableGame));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
    }
}
