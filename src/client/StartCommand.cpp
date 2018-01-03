//
// Created by sahar on 27/12/17.
//

#include <cstring>
#include "StartCommand.h"

StartCommand::StartCommand(){}

void StartCommand::execute(string input,bool &validArg, int clientSocket) {
    int n = write(clientSocket, input.c_str(), input.length());
    if (n == -1) {
        screenView.printServerDisconect();
        exit(-1);
    }

    int val;
    n = read(clientSocket, &val, sizeof (val));
    if (n == -1) {
        screenView.printServerDisconect();
        exit(-1);
    }

    if(val == -1) {
        validArg = false;
    } else {
        validArg = true;
    }
    ScreenView myView;
    myView.printStartCommand(val);
}