//
// Created by sahar on 27/12/17.
//

#include <cstring>
#include "StartCommand.h"
#include "ScreenView.h"

StartCommand::StartCommand(){}

void StartCommand::execute(string input, int clientSocket) {
 //  char arg[50];
   //  strcpy(arg,input.c_str());
    int n = write(clientSocket, input.c_str(), input.length());
    if (n == -1) {
        throw "Error writing arg1to socket";
    }
    char i[50];
    /////////////////   if not use int
    n = read(clientSocket, &i, sizeof(i));
    if (n == -1) {
        throw "Error writing arg1to socket";
    }

    ScreenView myView;
    myView.coutToScreen(i);

}