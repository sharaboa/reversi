//
// Created by sahar on 26/12/17.
//


#include "StartCommand.h"

StartCommand::StartCommand() {}

void StartCommand::execute(string args, int clientSocket) {
    bool validName = true;
    Game newGame;
   string arg;
    ///////maybe needs to ust str copy
    newGame.gameName = args;
    newGame.xSocket = clientSocket;
    for(int i = 0; i < gamesList->getGamesList().size(); i++){
        if (gamesList->getGamesList().at(i).gameName.compare(args) == 0) {
            validName = false;
        }
    }
    if(validName){
        gamesList->addGame(newGame);
   arg = "opened a new Room";

    }
    else {
        arg = "Error opened a new Room";
    }
    char msg[50];
    strcpy(msg,arg.c_str());
    int n = write(clientSocket, &msg, sizeof(msg));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
    }
}