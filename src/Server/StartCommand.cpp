//
// Created by sahar on 26/12/17.
//


#include "StartCommand.h"

StartCommand::StartCommand(const vector <Game> &gamesList): gamesList(gamesList) {}

void StartCommand::execute(string args, int clientSocket) {
    bool canStart = true;
    Game newGame;
    ///////maybe needs to ust str copy
    newGame.gameName = args;
    newGame.xSocket = clientSocket;
    for(int i = 0; i < gamesList.size(); i++){
        if (gamesList.at(i).gameName.compare(args) == 0) {
            canStart = false;
        }
    }
    if(canStart) {
        int succesCode = 1;
        int n = write(clientSocket, &succesCode, sizeof(succesCode));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
        }

        gamesList.push_back(newGame);
    }
    else {
        int errorCode = -1;
        int n = write(clientSocket, &errorCode, sizeof(errorCode));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
        }
    }
}