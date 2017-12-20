//
// Created by sahar on 19/12/17.
//

#include "StartCommand.h"

StartCommand::StartCommand();
void StartCommand::execute(string args, int clientSocket) {
    game newGame;
    ///////maybe needs to ust str copy
    newGame.gameName = args;
    newGame.xSocket = clientSocket;
    for(int i = 0; i < server.getList().size(); i++){
        if(server.getList().at(i).gameName.compare(args) !=0){
            server.getList().push_back(newGame);
        }
        else{
            server.writeToClient(clientSocket,"-1");
        }
    }
}