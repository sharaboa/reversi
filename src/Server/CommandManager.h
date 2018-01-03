//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_COMMANDMANAGER_H
#define SERVER_COMMANDMANAGER_H

#include <map>
#include "Command.h"

class CommandManager {
public:
    /**
    * manage the commands of the client
    */
    CommandManager();
    /**
     * destructor
     */
    ~CommandManager();
    /**
     * exe the commands of the client
     * @param input the client command
     * @param clientSocket the client socket num
     */
    void executeCommand(string input,int clientSocket);
private:
    map<string, Command*> commandsMap;
};


#endif //SERVER_COMMANDMANAGER_H