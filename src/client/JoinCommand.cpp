//
// Created by sahar on 27/12/17.
//

#include <iostream>
#include "JoinCommand.h"
#include "ServerCom.h"


JoinCommand::JoinCommand() {}

void JoinCommand::execute(string input,bool &validArg, int clientSocket) {


    ServerCom serverCom(clientSocket);
    serverCom.writeString(input);

    int i;
    serverCom.readInt(i);

    if (i == -1){
        validArg = false;
    }else{
        validArg = true;
    }
}