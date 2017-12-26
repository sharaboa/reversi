//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_HANDELCLIENT_H
#define SERVER_HANDELCLIENT_H

#include "CommandManager.h"

class HandelClient {
public:
    HandelClient(int clientSocket);
    static void *readCommand(void *tArgs);
private:
    static CommandManager manager;
    int clientSocket;
};


#endif //SERVER_HANDELCLIENT_H
