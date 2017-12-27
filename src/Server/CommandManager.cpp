//
// Created by sahar on 26/12/17.
//

#include "CommandManager.h"


#include "StartCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"
#include "CloseCommand.h"
#include "closeServerCommand.h"


CommandManager::CommandManager() {
    //add to the list
    commandsMap["start"] = new StartCommand(gamesList);
    //vector
    commandsMap["list_games"] = new ListGamesCommand(gamesList);
    commandsMap["join"] = new JoinCommand(gamesList);
  //  commandsMap["play"] = new PlayCommand(gamesList);
    commandsMap["close"] = new CloseCommand(gamesList);
    commandsMap["closeServer"] = new closeServerCommand();
}
void CommandManager::executeCommand(string input,int clientSocket) {
    int s = input.find('<');
    int y = input.find('>');
    string command = input.substr(0,s);
    string arg = input.substr(s+1,y);
    arg.erase(arg.end()-1,arg.end());
    //strncpy(command,input,y);
    Command *commandObj = commandsMap[command];
    commandObj->execute(arg,clientSocket);
}
CommandManager::~CommandManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}