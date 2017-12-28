//
// Created by sahar on 27/12/17.
//

#include "closeServerCommand.h"

void closeServerCommand::execute(string arg, int clientSocket) {
    for(int i=0;i < this->getGamesList().size();i++){
      closeManager.executeCommand("close", this->getGamesList().at(i).xSocket);
        closeManager.executeCommand("close", this->getGamesList().at(i).oSocket);

    }
}