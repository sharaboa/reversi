//
// Created by or on 21/12/17.
//

#include "CloseCommand.h"

CloseCommand::CloseCommand(vector <Game> gamesList) {}

void CloseCommand::execute(string arg, int clientSocket) {
    for (int i = 0;i<gamesList.size();i++) {
        if(gamesList.at(i).gameName == args) {
            close(gamesList.at(i).xSocket);
            close(gamesList.at(i).oSocket);
            gamesList.erase(gamesList.begin() + i);
        }
    }
}