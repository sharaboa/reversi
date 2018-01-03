//
// Created by sahar on 26/12/17.
//


#include "StartCommand.h"

StartCommand::StartCommand() {}

void StartCommand::execute(string room, int clientSocket) {
    bool validName = true;
    int val;
    Game newGame;
    newGame.gameName = room;
    newGame.xSocket = clientSocket;
    newGame.oSocket = -2;

    for(int i = 0; i < getGameList()->getGamesList().size(); i++){
        if (getGameList()->getGamesList().at(i).gameName.compare(room) == 0) {
            validName = false;
        }
    }

    if(validName){
        getGameList()->addGame(newGame);
        val = 1;
    } else {
        val = -1;
    }

    int n = write(clientSocket, &val, sizeof(val));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
    }
}