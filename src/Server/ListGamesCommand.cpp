//
// Created by sahar on 26/12/17.
//

#include "ListGamesCommand.h"

ListGamesCommand::ListGamesCommand() {}
void ListGamesCommand::execute(string arg, int clientSocket){
    vector <string> availableGame;
    for (int i = 0;i<gamesList->getGamesList().size();i++) {
        /// תנאי בעייתי
        if (gamesList->getGamesList().at(i).oSocket == NULL)
           availableGame.push_back(gamesList->getGamesList().at(i).gameName);

    }

    int i = 0;
    if(!availableGame.empty()){
        i=availableGame.size();
    }
    int n = write(clientSocket, &i, sizeof(i));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
    }
    for(int i=0;i<availableGame.size();i++){
      /*  char arg[50];
        strcpy(arg,gamesList->getGamesList().at(i).gameName.c_str());*/
        int n = write(clientSocket, gamesList->getGamesList().at(i).gameName.c_str(), gamesList->getGamesList().at(i).gameName.length());
        if (n == -1) {
            cout << "Error writing to socket" << endl;
        }
    }
}