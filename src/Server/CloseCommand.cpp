//
// Created by sahar on 26/12/17.
//

#include "CloseCommand.h"

CloseCommand::CloseCommand(const vector <Game> &gamesList):gamesList(gamesList) {}

void CloseCommand::execute(string arg, int clientSocket) {
    for (int i = 0;i<gamesList.size();i++) {
        if(gamesList.at(i).gameName == arg) {
            close(gamesList.at(i).xSocket);
            close(gamesList.at(i).oSocket);
            gamesList.erase(gamesList.begin() + i);
        }
    }
}