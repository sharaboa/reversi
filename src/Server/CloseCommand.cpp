//
// Created by sahar on 26/12/17.
//

#include "CloseCommand.h"

CloseCommand::CloseCommand() {}

void CloseCommand::execute(string arg, int clientSocket) {
    for (int i = 0;i<gamesList->getGamesList().size();i++) {
        if(gamesList->getGamesList().at(i).gameName == arg) {
            close(gamesList->getGamesList().at(i).xSocket);
            close(gamesList->getGamesList().at(i).oSocket);
            gamesList->removeGame(arg);
        }
    }
}