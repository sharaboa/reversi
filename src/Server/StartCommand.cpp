//
// Created by sahar on 26/12/17.
//


#include "StartCommand.h"

StartCommand::StartCommand() {}

void StartCommand::execute(string args, int clientSocket) {
    bool canStart = true;
    Game newGame;
    ///////maybe needs to ust str copy
    newGame.gameName = args;
    newGame.xSocket = clientSocket;
    for(int i = 0; i < this->getGamesList().size(); i++){
        if (this->getGamesList().at(i).gameName.compare(args) == 0) {
            canStart = false;
        }
    }
    if(canStart)
        this->addGame(newGame);
    else {
        int errorCode = -1;
        int n = write(clientSocket, &errorCode, sizeof(errorCode));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
        }
    }
}