//
// Created by sahar on 03/01/18.
//

#include <unistd.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include "ServerCom.h"
ServerCom::ServerCom(int clientSocket): clientSocket(clientSocket){}

void ServerCom::readInt(int &output) {
    int n = read(clientSocket, &output, sizeof(output));
    if (n == -1) {
        screenView.printServerDisconect();
        exit(0);
    }
    if (n == 0) {
        screenView.printServerDisconect();
        exit(0);
    }
}
void ServerCom::writeInt(int &input) {
    int n = write(clientSocket, &input, sizeof(input));
    if (n == -1) {
        screenView.printServerDisconect();
        exit(0);
    }
}
void ServerCom::readString(string &str) {
    char output[50];
    /////////////////   if not use int
    int  n = read(clientSocket, &output, sizeof(output));
    if (n == -1) {
        screenView.printServerDisconect();
        exit(0);
    }
    if (n == 0) {
        screenView.printServerDisconect();
        exit(0);
    }
    string temp(output);
    str.append(temp);
}
void ServerCom::writeString(string input) {
    input.insert(input.end(),'\0');
    int n = write(clientSocket, input.c_str(), input.length());
    if (n == -1) {
        screenView.printServerDisconect();
        exit(0);
    }
}