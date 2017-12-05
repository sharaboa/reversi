//
// Created by or on 03/12/17.
//

#include "ClientPlayer.h"
#include "ClientPlayer.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
using namespace std;
ClientPlayer::ClientPlayer(Symbol symbol,const char *serverIP, int serverPort): HumanPlayer(symbol),serverIP(serverIP), serverPort(6886), clientSocket(0) {
    cout << "ClientPlayer" << endl;
}
void ClientPlayer::connectToServer() {
// Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
// Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }

// Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof address, AF_INET);
    if(server == NULL) {
        throw "Host is unreachable";
    }
// Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char*)&address,sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
//htonsconverts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);

// Establish a connection with the TCP server
    if(connect(clientSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    cout<<"Connected to server"<<endl;
    int n = read(clientSocket, &clientNum, sizeof(clientNum));
    if (n == -1) {
        throw
                "Error reading result from socket";
    }

}


Disc ClientPlayer::playerLogic(Player opponentPlayer) {
    int arg1, arg2, n;
    if (clientNum == 1 && symbol == X || clientNum == 2 && symbol == O) {
        optionStack.isRepeat();
        cout << (char) symbol << ": It's your move." << endl << "Your possible moves: ";
        for (int i = 0; i < optionStack.getAmount(); i++) {
            cout << "(" << optionStack.getDisc(i).getRowLocation() << "," << optionStack.getDisc(i).getColumnLocation()
                 << ") ";
        }
        cout << endl << endl << "Please enter your move row,col:";
        while (true) {
            char input[50];
            cin.getline(input, 50);
            fromInputToDisc(input);

            if (optionStack.appear(myChoise)) {

                n = write(clientSocket, &arg1, sizeof(arg1));
                if (n == -1) {
                    throw "Error writing arg1to socket";
                }
                n = write(clientSocket, &arg2, sizeof(arg2));
                if (n == -1) {
                    throw "Error writing arg2to socket";
                }
                return myChoise;

            } else {
                cout << endl << endl << "illegal move! Please enter your move row,col:";
            }
        }
    } else {
        cout<<"waiting for other player's move...\n";
        n = read(clientSocket, &arg1, sizeof(arg1));
        if (n == -1) {
            throw "Error writing arg1to socket";
        }
        n = read(clientSocket, &arg2, sizeof(arg2));
        if (n == -1) {
            throw "Error writing arg2to socket";
        }
        myChoise.setDisc(arg1, arg2);
        return myChoise;
    }
}
int ClientPlayer::getClientNum() {
    return clientNum;
}
int ClientPlayer::getClientSocket() {
    return clientSocket;
}
void ClientPlayer::setClientNum(int myClientNum) {
    clientNum = myClientNum;
}
void ClientPlayer::setClientSocket(int myClientSocket) {
    clientSocket = myClientSocket;
}
