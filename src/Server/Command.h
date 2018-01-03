//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H


#include <vector>
#include "GameStruct.h"
#include "GamesListManager.h"
#include <unistd.h>

class Command {
public:
    /**
     * exe the commands of the client
     * @param input the client command
     * @param clientSocket the client socket num
     */
    virtual void execute(string arg, int clientSocket) = 0;
    /**
     * destractur
     */
    virtual ~Command() {}
protected:
    /**
     * singelton list access
     * @return - list of games
     */
    GamesListManager* getGameList() const {
        return GamesListManager::getInstance();
    }
};


#endif //SERVER_COMMAND_H