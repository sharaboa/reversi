//
// Created by sahar on 27/12/17.
//

#include <cstring>
#include "StartCommand.h"
#include "ScreenView.h"


StartCommand::StartCommand(){}

void StartCommand::execute(string input, int clientSocket) {
    char arg[50];
    strcpy(arg,input.c_str());
    int n = write(clientSocket, &input, sizeof(input));
    if (n == -1) {
        throw "Error writing arg1to socket";
    }
    int i;
    /////////////////   if not use int
    n = read(clientSocket, &i, sizeof(i));
    if (n == -1) {
        throw "Error writing arg1to socket";
    }

    ScreenView myView;
 if (i==-1) {
     myView.coutToScreen("Erorr starting a room");
 }
if(i==1){
     myView.coutToScreen("Room Started");
 }

}