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
        ThreadArgs args;
        args.clientSocket1 = clientSocket;
        int rc = pthread_create(&thread, NULL, readCommand, &args);
        if (rc) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }

}

void *HandelClient::readCommand(void *tArgs) {
    string command;
    while (!command.compare("close")) {

        struct ThreadArgs *args = (struct ThreadArgs *) tArgs;
        int n = read(args->clientSocket1, &command, sizeof(command));

        if (n == -1) {
            cout << "Error reading rowCordination" << endl;
            exit(-1);
        }
        if (n == 0) {
            cout << "Client disconnected" << endl;
            exit(-1);
        }
        CommandManager manager;
        manager.executeCommand(command, args->clientSocket1);
    }
}
