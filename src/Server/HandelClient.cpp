//
// Created by sahar on 26/12/17.
//

#include <cstdlib>
#include <sstream>
#include "HandelClient.h"
#include "ThreadList.h"
#define MAX_COMMAND_LEN 20

struct handleArgs {
    int clientSocket1;
    pthread_t *tID;
};

HandelClient::HandelClient(int clientSocket) :clientSocket(clientSocket){
  //  pthread_t thread;
}

void *HandelClient::readCommand(void *tArgs) {
    struct handleArgs *args = (struct handleArgs *) tArgs;
    char input[MAX_COMMAND_LEN];
    int byteRecived = 0;
    byteRecived = read(args->clientSocket1, input, MAX_COMMAND_LEN);
    if (byteRecived == -1) {
        cout << "Error reading rowCordination" << endl;
        exit(-1);
    }
    string str(input);
    istringstream iss(str);
    string command;
    iss >> command;


    /*if(command.compare("join") == 0) {
        ThreadList::getInstance()->addThread(pthread_self());
    }*/
    CommandManager manager;
    manager.executeCommand(str,args->clientSocket1);
}