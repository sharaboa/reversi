//
// Created by sahar on 26/12/17.
//

#include "ListGamesCommand.h"

ListGamesCommand::ListGamesCommand() {}
void ListGamesCommand::execute(string arg, int clientSocket){
    vector <string> availableGame;
    for (int i = 0;i<getGameList()->getGamesList().size();i++) {
        availableGame.push_back(getGameList()->getGamesList().at(i).gameName);
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
        char arg[50];
        strcpy(arg,availableGame.at(i).c_str());
        int n = write(clientSocket,&arg, sizeof(arg));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
        }
    }
}