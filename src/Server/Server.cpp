//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include "Server.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <pthread.h>
#include <cstdlib>
#include <complex>
#include <bits/sigthread.h>
#include "HandelClient.h"

using namespace std;
#define MAX_CONNECTED_CLIENTS 10

struct ThreadArgs {
    int serverSocket1;
};

Server::Server() {

   // string p;
  //  ifstream inFile;
   // inFile.open("setting.txt");
  //  inFile >> p;
    port = 8888;
  //  inFile >> port;
  //  inFile.close();
}
void Server::start() {
  //  numOfClients = 0;
// Create a socket point
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
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
        throw runtime_error("Error on binding");
    }
// Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    ThreadArgs args;
    args.serverSocket1 = serverSocket;
   //thread for accepting the client
    pthread_t thread;

    int rc = pthread_create(&thread, NULL, connect, &args);

    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }
    while (true){

    }
    /*string command ;

    while(true){
        if(!command.compare("close server"))
        {
            cout << "Enter command: ";
            cin >> command;
        }
        else{
           // myManager.executeCommand("closeServer", NULL);
           pthread_cancel(thread);
           exitThreads();
            break;

        }
    }*/
}



void Server::closeGame(Game game) {
    close(game.xSocket);
    close(game.oSocket);
    /////// need to close both threads ////////////
}


void * Server::connect (void *tArgs) {
    while (true) {
        cout << "Waiting for client connections..." << endl;
        struct ThreadArgs *args = (struct ThreadArgs *) tArgs;
        // Define the client socket's structures
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLen = sizeof((struct sockaddr *) &clientAddress);
        int clientSocket = accept(args->serverSocket1, (struct sockaddr *) &clientAddress, &clientAddressLen);
        //  socketsList.push_back(clientSocket);
        cout << "Client connected" << endl;
        HandelClient handleClient(clientSocket);
        while (true){

        }

    }
}

void Server:: exitThreads() {
   /*//change to game list
    for (int i = 0;i < myManager;i++) {
        pthread_cancel(threadsList.at(i));
    }*/
}