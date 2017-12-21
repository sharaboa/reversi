//
// Created by sahar on 19/12/17.
//

#include "ListGamesCommand.h"

/*struct Output{
    vector<string> availableGame;
} out;*/

ListGamesCommand::ListGamesCommand(vector <Game> gamesList) {}

void ListGamesCommand::execute(string args, int clientSocket){
    vector <string> availableGame;
    for (int i = 0;i<gamesList.size();i++)
        if(!(gamesList.at(i).oSocket))
            availableGame.push_back(gamesList.at(i).gameName);
    int n = write(clientSocket, &availableGame, sizeof(availableGame));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
    }
    //server.writeToClient(clientSocket,out);
}
