//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include "Server.h"
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;
#define MAX_CONNECTED_CLIENTS 2

Server::Server() : serverSocket(0) {
    string p;
    ifstream inFile;
    inFile.open("setting.txt");
    inFile >> p;
    inFile >> port;
    inFile.close();
}
void Server::start() {
    numOfClients = 0;
// Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw runtime_error ("Error on binding");
    }
// Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
// Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof((struct sockaddr*)&clientAddress);
    //connecting to client
    while(true) {
        connect(clientAddress, clientAddressLen);
        ClientCom();
// Close communication with the client
        close(clientSocket1);
        close(clientSocket2);
        numOfClients = 0;
    }
}


void Server::stop() {
    close(serverSocket);
}


void Server::connect (sockaddr_in &clientAddress,socklen_t &clientAddressLen) {
    while (numOfClients < MAX_CONNECTED_CLIENTS) {
// Accept a new client connection
        cout << "Waiting for client connections..." << endl;

        //player1
        if (numOfClients == 0) {
            clientSocket1 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
            cout << "Client connected" << endl;
            numOfClients++;
            int i = 1;
            int n = write(clientSocket1, &i, sizeof(i));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            if (clientSocket1 == -1) {
                throw runtime_error("Error on accept client 1");
            }
        }
        //player2
        if (numOfClients == 1) {
            clientSocket2 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
            cout << "Client connected" << endl;
            numOfClients++;
            int i = 2;
            //write to first player that the other player connected
            int n = write(clientSocket1, &i, sizeof(i));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            if (clientSocket1 == -1) {
                throw runtime_error("Error on accept client 1");
            }
            n = write(clientSocket2, &i, sizeof(i));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            if (clientSocket2 == -1) {
                throw runtime_error("Error on accept client 2");
            }
        }
    }
}


void Server::ClientCom() {
    while (true) {
        if (!handleClient(clientSocket1, clientSocket2)) {
            break;
        }
        if (!handleClient(clientSocket2, clientSocket1)) {
            break;
        }
    }
}

// Handle requests from a specific client
bool Server::handleClient(int clientSocket, int clientSocket2) {
    int rowCordination, colCordination;
// Read new exercise arguments - read coordinates as two int
    int n = read(clientSocket, &rowCordination, sizeof (rowCordination));

    if (n == -1) {
        cout << "Error reading rowCordination" << endl;
        return false;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return false;
    }
    n = read(clientSocket, &colCordination, sizeof (colCordination));
    if (n == -1) {
        cout << "Error reading colCordination" << endl;
        return false;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return false;
    }
    if(rowCordination == -2 && colCordination== -2) {
        return true;
    }
// Write the result back to the client - write coordinates as two int
    n = write(clientSocket2, &rowCordination, sizeof(rowCordination));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return false;
    }
    n = write(clientSocket2, &colCordination, sizeof(colCordination));
    if (n == -1) {
        cout << "Error writing to socket" << endl;
        return false;
    }
    return true;
}