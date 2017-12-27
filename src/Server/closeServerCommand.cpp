//
// Created by sahar on 27/12/17.
//

#include "closeServerCommand.h"

void closeServerCommand::execute(string arg, int clientSocket) {
    for(int i=0;i < gamesList.size();i++){
      closeManager.executeCommand("close", gamesList.at(i).xSocket);
        closeManager.executeCommand("close", gamesList.at(i).oSocket);

    }
}