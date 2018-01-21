//
// Created by sahar on 27/12/17.
//

#include <cstring>
#include <sstream>
#include "ListOfGamesCommand.h"
#include "ScreenView.h"
#include "ServerCom.h"
ListOfGamesCommand::ListOfGamesCommand() {}

void ListOfGamesCommand::execute(string input,bool &validArg, int clientSocket) {
    ServerCom serverCom(clientSocket);
    serverCom.writeString(input);

    int numOfGames;

    serverCom.readInt(numOfGames);
    ScreenView myView;
    if(numOfGames == 0 ){
        myView.coutToScreen("No availabel game, Pls open a new one");
    }


    for (int j = 0; j < numOfGames ; j++) {
        string str;
        serverCom.readString(str);
        myView.coutToScreen(str);
        str.clear();
    }
    close(clientSocket);
}