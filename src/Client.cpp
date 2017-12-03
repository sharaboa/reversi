//
// Created by or on 03/12/17.
//

#include "Client.h"
#include "Client.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
using namespace std;
Client::Client(const char *serverIP, int serverPort): serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
    cout << "Client" << endl;
}
void Client::connectToServer() {
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


    int Client::sendExercise(int arg1, char op, int arg2) {
// Write the exercise arguments to the socket
        int n = write(clientSocket, &arg1, sizeof(arg1));
        if (n == -1) {
            throw "Error writing arg1to socket";
        }
        n = write(clientSocket, &op, sizeof(op));
        if (n == -1) {
            throw "Error writing op to socket";
        }
        n = write(clientSocket, &arg2, sizeof(arg2));
        if (n == -1) {
            throw "Error writing arg2to socket";
        }
// Read the result from the server
        int result;
        n = read(clientSocket, &result, sizeof(result));
        if (n == -1) {
            throw
                    "Error reading result from socket";
        }
        return result;
    }
}