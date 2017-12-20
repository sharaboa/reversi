//
// Created by sahar on 19/12/17.
//

#include "ListGamesCommand.h"


ListGamesCommand::ListGamesCommand();
void ListGamesCommand::execute(string args, int clientSocket){
    vector <string> gameList;
    for (int i = 0;i<server.getList().size();i++)
        gameList.push_back(server.getList().at(i).gameName);
    server.writeToClient(clientSocket)
}
