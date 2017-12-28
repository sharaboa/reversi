//
// Created by sahar on 26/12/17.
//

#include <cstdlib>
#include "HandelClient.h"

struct ThreadArgs {
    int clientSocket1;
};
HandelClient::HandelClient(int clientSocket) :clientSocket(clientSocket){
    pthread_t thread;
        //ThreadArgs args;
        //args.clientSocket1 = clientSocket;
    int rc = pthread_create(&thread, NULL, readCommand, (void *)clientSocket);
    if (rc) {
        cout << "Error: unable to create thread, " << rc << endl;
        exit(-1);
    }

}

void *HandelClient::readCommand(void *tArgs) {
    char command[50];
   // while (!command.compare("close")) {
    long args = (long ) tArgs;
    //struct ThreadArgs *args = (struct ThreadArgs *) tArgs;

    //int n = read(args->clientSocket1, &command, sizeof(command));
    int n = read(args, &command, sizeof(command));
     if (n == -1) {
         cout << "Error reading rowCordination" << endl;
         exit(-1);
     }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        exit(-1);
    }
    CommandManager manager;
    //manager.executeCommand(command, args->clientSocket1);
    manager.executeCommand(command, args);
   // }
}
