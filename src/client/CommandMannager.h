//
// Created by sahar on 27/12/17.
//

#ifndef SRC_COMMANDMANNAGER_H
#define SRC_COMMANDMANNAGER_H


#include <map>
#include "ClientPlayer.h"
#include "Command.h"
class CommandMannager {
public:
    /**
     * manage the commands of the player
     */
    CommandMannager();
    /**
     * destractor
     */
    ~CommandMannager();
    /**
     * exe the player commands
     * @param input the command of the player
     * @param validArg usued as an indication to a valid arg (valid from the server side)
     * @param clientSocket the client socket (com with the server)
     */
    void executeCommand(string input,bool &validArg,int clientSocket);
    /**
     * usued as an indication to a valid command (valid from the client side)
     * @param command the command of the player
     * @return true if valid false otherwise
     */
    bool validCommand(string command);
private:
    map<string, Command*> commandsMap;



};


#endif //SRC_COMMANDMANNAGER_H