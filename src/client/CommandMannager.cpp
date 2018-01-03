//
// Created by sahar on 27/12/17.
//

#include "CommandMannager.h"
#include "StartCommand.h"
#include "JoinCommand.h"

#include "ListOfGamesCommand.h"
#include <sstream>

CommandMannager::CommandMannager() {
    commandsMap["start"] = new StartCommand();
    commandsMap["join"] = new JoinCommand();
    commandsMap["list_games"] = new ListOfGamesCommand();
}

void CommandMannager::executeCommand(string input,bool &validArg,int clientSocket) {
    istringstream iss(input);
    string command;
    command.clear();
    iss >> command;

    Command *commandObj = commandsMap[command];
    commandObj->execute(input,validArg,clientSocket);
}

bool CommandMannager::validCommand(string command){

    if(commandsMap.find(command) == commandsMap.end()) {
        return false;
    } else {
        return true;
    }
}


CommandMannager::~CommandMannager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}