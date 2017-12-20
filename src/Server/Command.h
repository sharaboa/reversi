//
// Created by or on 19/12/17.
//

#ifndef REVERSI_COMMAND_H
#define REVERSI_COMMAND_H

#endif //REVERSI_COMMAND_H

#include <vector>
#include<string>
#include "Server.h"

using namespace
std;
class Command {
public:
    virtual void execute(string args, int clientSocket);
    virtual ~Command() {}

protected:
    Server &server;
};