//
// Created by sahar on 03/01/18.
//

#include <unistd.h>
#include <iostream>
#include "ServerCom.h"
ServerCom::ServerCom(int clientSocket): clientSocket(clientSocket){}

void ServerCom::readInt(int &output) {
    int n = read(clientSocket, &output, sizeof(output));
    if (n == -1) {
        screenView.printServerDisconect();
        exit(-1);
    }
    if (n == 0) {
        screenView.printServerDisconect();
        exit(-1);
    }


}
void ServerCom::writeInt(int &input) {
    int n = write(clientSocket, &input, sizeof(input));
    if (n == -1) {
        screenView.printServerDisconect();
        exit(-1);
    }
}