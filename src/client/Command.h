//
// Created by sahar on 27/12/17.
//

#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H




#include <unistd.h>
#include <string>
#include "ScreenView.h"

using namespace std;

class Command {
public:
    /**
     * abstract fun to execute command
     * @param arg - name
     * @param validStart - cheking if arg legal
     * @param clientSocket - in order to communicate
     */
    virtual void execute(string arg,bool &validStart, int clientSocket) = 0;
    /**
     * destractor
     */
    virtual ~Command() {}

protected:
    ScreenView screenView;
};


#endif //CLIENT_COMMAND_H