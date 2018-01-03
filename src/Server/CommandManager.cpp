//
// Created by sahar on 26/12/17.
//

#include "CommandManager.h"


#include "StartCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"


#include <sstream>


CommandManager::CommandManager() {
    commandsMap["start"] = new StartCommand;
    commandsMap["list_games"] = new ListGamesCommand;
    commandsMap["join"] = new JoinCommand;
}

void CommandManager::executeCommand(string input,int clientSocket) {
    istringstream iss(input);
    string command;
    iss >> command;
    string arg;
    iss >> arg;
    Command *commandObj = commandsMap[command];
    if(commandObj != NULL ) {
        commandObj->execute(arg, clientSocket);
    }
}

CommandManager::~CommandManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}