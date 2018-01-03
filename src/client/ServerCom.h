//
// Created by sahar on 03/01/18.
//

#ifndef CLIENT_SERVERCOM_H
#define CLIENT_SERVERCOM_H

#include <string>
#include "ScreenView.h"

using namespace std;

class ServerCom {
public:
    /**
     * constructor for communication between client and server
     * @param clientSocket 
     */
    ServerCom(int clientSocket);
    /**
     * read func
     * @param output - read int
     */
    void readInt(int &output);
    /**
     * write func
     * @param input - write int
     */
    void writeInt(int &input);

private:
    int clientSocket;
    ScreenView screenView;
};


#endif //CLIENT_SERVERCOM_H