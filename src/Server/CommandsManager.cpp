//
// Created by or on 19/12/17.
//

#include <cstring>
#include "CommandsManager.h"
#include "StartCommand.h"
#include "ListGamesCommand.h"


//#include "PrintCommand.h"


CommandsManager::CommandsManager() {
    //commandsMap["print"] = new PrintCommand();

    //add to the list
    commandsMap["start"] = new StartCommand();
    //vector
    commandsMap["list_games"] = new ListGamesCommand();
    commandsMap["join"] = new JoinCommand();
    commandsMap["play"] = new PlayCommand();
    commandsMap["close"] = new CloseCommand();

// Add more commands...
}
void CommandsManager::executeCommand(string input) {
    int i = input.find('<');
    int y = input.find('>');
    string command = input.substr(0,i);
    string arg = input.substr(i+1,y);
    arg.erase(arg.end()-1,arg.end());
    strncpy(command,input,y);
    Command *commandObj = commandsMap[command];
    commandObj->execute(arg);

}
CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}