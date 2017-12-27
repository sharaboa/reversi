//
// Created by or on 26/12/17.
//

#include "PlayCommand.h"

PlayCommand::PlayCommand(int clientSocket1, int clientSocket2): clientSocket1(clientSocket1), clientSocket2(clientSocket2){}

void PlayCommand::ClientCommunication() {
    while (true) {
        if (!handleTurn(clientSocket1, clientSocket2)) {
            break;
        }
        if (!handleTurn(clientSocket2, clientSocket1)) {
            break;
        }
    }
}


// Handle requests from a specific client
bool PlayCommand::handleTurn(int clientSocket1,int clientSocket2) {
    int rowCordination, colCordination;
// Read new exercise arguments - read coordinates as two int
    int n = read(clientSocket1, &rowCordination, sizeof (rowCordination));

    if (n == -1) {
        cout << "Error reading rowCordination" << endl;
        return false;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return false;
    }
    n = read(clientSocket1, &colCordination, sizeof (colCordination));
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