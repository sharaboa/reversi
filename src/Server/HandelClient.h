//
// Created by sahar on 26/12/17.
//

#ifndef SERVER_HANDELCLIENT_H
#define SERVER_HANDELCLIENT_H

#include "CommandManager.h"

class HandelClient {
public:
    /**
     * handeling the client commands
     * @param clientSocket the socket of the client
     */
    HandelClient(int clientSocket);
    /**
     * readind the clients command
     * @param tArgs the client soxket
     * @return void
     */
    static void *readCommand(void *tArgs);
private:
    int clientSocket;
};


#endif //SERVER_HANDELCLIENT_H