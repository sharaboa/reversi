//
// Created by or on 19/12/17.
//

#include <cstring>
#include "CommandsManager.h"
#include "StartCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"
#include "PlayCommand.h"
#include "CloseCommand.h"


//#include "PrintCommand.h"


CommandsManager::CommandsManager() {

    //add to the list
    commandsMap["start"] = new StartCommand(gamesList);
    //vector
    commandsMap["list_games"] = new ListGamesCommand(gamesList);
    commandsMap["join"] = new JoinCommand(gamesList);
    commandsMap["play"] = new PlayCommand(gamesList);
    commandsMap["close"] = new CloseCommand(gamesList);

}
void CommandsManager::executeCommand(string input,int clientSocket) {
    int s = input.find('<');
    int y = input.find('>');
    string command = input.substr(0,s);
    string arg = input.substr(s+1,y);
    arg.erase(arg.end()-1,arg.end());
    //strncpy(command,input,y);
    Command *commandObj = commandsMap[command];
    commandObj->execute(arg,clientSocket);
}
CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}