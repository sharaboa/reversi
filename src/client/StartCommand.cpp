//
// Created by sahar on 27/12/17.
//

#include "StartCommand.h"
#include "ScreenView.h"

StartCommand::StartCommand(){}

void StartCommand::execute(string input, int clientSocket) {

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