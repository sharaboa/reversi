//
// Created by sahar on 27/12/17.
//

#include "JoinCommand.h"
JoinCommand::JoinCommand() {}

void JoinCommand::execute(string input, int clientSocket) {
    int n = write(clientSocket, &input, sizeof(input));
    if (n == -1) {
        throw "Error writing arg1to socket";
    }

}