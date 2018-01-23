//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include "Server.h"
#include <fstream>
#include <pthread.h>
#include <cstdlib>
#include <complex>
#include <bits/sigthread.h>
#include "HandelClient.h"
#include "ThreadList.h"
#include "ThreadPool.h"

using namespace std;
#define MAX_CONNECTED_CLIENTS 10

struct ThreadArgs {
    int serverSocket1;
};

struct handleArgs {
    int clientSocket1;
  //  pthread_t *tID;
};

Server::Server(): serverSocket(0), serverThreadId(0),threadPool(5) {
    tasks[MAX_CONNECTED_CLIENTS];
    string p;
    ifstream inFile;
    inFile.open("setting.txt");
    inFile >> p;
    inFile >> port;
    inFile.close();
}
void Server::start() {
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
        throw runtime_error("Error on binding");
    }
// Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    ThreadArgs args;
    args.serverSocket1 = serverSocket;
    //thread for accepting the client
    int rc = pthread_create(&serverThreadId, NULL, connect, (void *) this);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }
}


void * Server::connect (void *s) {
    Server* server = (Server*) s;
    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof((struct sockaddr *) &clientAddress);

    for (int i = 0; i < MAX_CONNECTED_CLIENTS; i++) {
        cout << "Waiting for client connections..." << endl;
        int clientSocket = accept(server->getServerSocket(), (struct sockaddr *) &clientAddress, &clientAddressLen);
        cout << "Client connected" << endl;
        HandelClient handleClient(clientSocket);
        //pthread_t thread;
        handleArgs args2;
        args2.clientSocket1 = clientSocket;
        server->getPool().addTask(new Task(handleClient.readCommand, &args2));
    }
}


long Server::getServerSocket() {
    return serverSocket;
}

void Server::stop() {
    pthread_cancel(serverThreadId);
    close(serverSocket);
    threadPool.terminate();
    for (int i = 0; i < GamesListManager::getInstance()->getGamesList().size(); i++) {
        close(GamesListManager::getInstance()->getGamesList().at(i).xSocket);
        close(GamesListManager::getInstance()->getGamesList().at(i).oSocket);
    }

    cout << "Server stopped" << endl;
}

ThreadPool& Server::getPool() {
    return threadPool;
}

