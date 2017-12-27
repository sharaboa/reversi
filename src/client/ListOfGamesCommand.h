//
// Created by sahar on 27/12/17.
//

#ifndef CLIENT_LISTOFGAMESCOMMAND_H
#define CLIENT_LISTOFGAMESCOMMAND_H

#include <vector>
#include "Command.h"

class ListOfGamesCommand: public Command {
public:
    ListOfGamesCommand();
    virtual void execute(string input,int clientSocket);

private:
    vector <string> listGame;
};


#endif //CLIENT_LISTOFGAMESCOMMAND_H
