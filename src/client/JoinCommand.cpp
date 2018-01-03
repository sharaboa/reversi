//
// Created by sahar on 27/12/17.
//

#include <iostream>
#include "JoinCommand.h"



JoinCommand::JoinCommand() {}

void JoinCommand::execute(string input,bool &validArg, int clientSocket) {
    int n = write(clientSocket, input.c_str(), input.length());
    if (n == -1) {
        screenView.printServerDisconect();
        exit(-1);
    }

    int i;
    n = read(clientSocket,&i,sizeof(i));
    if (n == -1) {
        screenView.printServerDisconect();
        exit(-1);
    }
    if (i == -1){
        validArg = false;
    }else{
        validArg = true;
    }
}