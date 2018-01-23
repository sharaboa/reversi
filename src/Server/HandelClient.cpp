//
// Created by sahar on 26/12/17.
//

#include <cstdlib>
#include <sstream>
#include "HandelClient.h"
#define MAX_COMMAND_LEN 20


HandelClient::HandelClient(){}

void *HandelClient::readCommand(void *tArgs) {
    long client = (long) tArgs;
    char input[MAX_COMMAND_LEN];
    int byteRecived = 0;
    byteRecived = read(client, input, MAX_COMMAND_LEN);
    if (byteRecived == -1) {
        cout << "Error reading rowCordination" << endl;
        exit(-1);
    }
    string str(input);
    istringstream iss(str);
    string command;
    iss >> command;

    CommandManager manager;
    manager.executeCommand(str,client);
}