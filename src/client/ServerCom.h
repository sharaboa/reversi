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
     * constractor - connection between server and client
     * @param clientSocket
     */
    ServerCom(int clientSocket);
    /**
     * client read num
     * @param output number
     */
    void readInt(int &output);
    /**
     * client read int
     * @param input number
     */
    void writeInt(int &input);
    /**
     * client read str
     * @param str
     */
    void readString(string &str);
    /**
     * client write str
     * @param input
     */
    void writeString(string input);

private:
    int clientSocket;
    ScreenView screenView;
};


#endif //CLIENT_SERVERCOM_H