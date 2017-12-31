//
// Created by sahar on 27/12/17.
//

#include "CommandMannager.h"
#include "StartCommand.h"
#include "JoinCommand.h"
#include "CloseCommand.h"
#include "ListOfGamesCommand.h"

CommandMannager::CommandMannager() {
    commandsMap["start"] = new StartCommand();
    commandsMap["join"] = new JoinCommand();
    commandsMap["close"] = new CloseCommand();
    commandsMap["list_games"] = new ListOfGamesCommand();
}

void CommandMannager::executeCommand(string input,int clientSocket) {
    string command;
    long s = input.find('<');
    long y = input.find('>');
    command = input.substr(0, s);

    Command *commandObj = commandsMap[command];
    commandObj->execute(input,clientSocket);
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