//
// Created by sahar on 27/12/17.
//

#ifndef CLIENT_COMMAND_H
#define CLIENT_COMMAND_H




#include <unistd.h>
#include <string>

using namespace std;
class Command {
public:
    virtual void execute(string arg, int clientSocket) = 0;
    virtual ~Command() {}

};


#endif //CLIENT_COMMAND_H
