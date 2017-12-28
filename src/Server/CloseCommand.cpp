//
// Created by sahar on 26/12/17.
//

#include "CloseCommand.h"

CloseCommand::CloseCommand() {}

void CloseCommand::execute(string arg, int clientSocket) {
    for (int i = 0;i<this->getInstance()->getGamesList().size();i++) {
        if(this->getGamesList().at(i).gameName == arg) {
            close(this->getGamesList().at(i).xSocket);
            close(this->getGamesList().at(i).oSocket);
            this->removeGame(arg);
        }
    }
}