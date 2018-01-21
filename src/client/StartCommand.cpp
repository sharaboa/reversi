//
// Created by sahar on 27/12/17.
//

#include <cstring>
#include "StartCommand.h"
#include "ScreenView.h"
#include "ServerCom.h"
StartCommand::StartCommand(){}

void StartCommand::execute(string input,bool &validArg, int clientSocket) {
    ServerCom serverCom(clientSocket);
    serverCom.writeString(input);
    int str;
    serverCom.readInt(str);
    if(str== -1){
        validArg = false;
    }else{
        validArg = true;
    }
    ScreenView myView;
    myView.printStartCommand(str);

}