//
// Created by or on 19/12/17.
//

#ifndef REVERSI_COMMAND_H
#define REVERSI_COMMAND_H

#endif //REVERSI_COMMAND_H

#include <vector>
#include<string>
using namespace
std;
class Command {
public:
    virtual void execute(vector<string> args) = 0;
    virtual ~Command() {}
};