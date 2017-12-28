//
// Created by sahar on 27/12/17.
//

#include "closeServerCommand.h"

void closeServerCommand::execute(string arg, int clientSocket) {
    for(int i=0;i < gamesList->getGamesList().size();i++){
      closeManager.executeCommand("close", gamesList->getGamesList().at(i).xSocket);
        closeManager.executeCommand("close", gamesList->getGamesList().at(i).oSocket);

    }
}