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
     //  args.clientSocket1 = clientSocket;
        int rc = pthread_create(&thread, NULL, readCommand,(void *) clientSocket);
        if (rc) {
            cout << "Error: unable to create thread, " << rc << endl;
            exit(-1);
        }

}

void *HandelClient::readCommand(void *tArgs) {
    long a = (long )tArgs;
    string loop;
    /*
   while (loop.compare("close") != 0) {
       char arg[50];
      long a = (long )tArgs;

      //  struct ThreadArgs *args = (struct ThreadArgs *) tArgs;
        int n = read(a, &arg, sizeof(arg));

        if (n == -1) {
            cout << "Error reading rowCordination" << endl;
            exit(-1);
        }
        if (n == 0) {
            cout << "Client disconnected" << endl;
            exit(-1);
        }
        CommandManager manager;
       string command = arg;
       int s = command.find('<');
       loop = command.substr(0, s);
        manager.executeCommand(command, a);
       for (int i= 0;i<50;i++){
           arg[i] = NULL;
       }
    }*/
    while (loop.compare("close") != 0) {
        vector<char> buffer(4096);
        string rcv;
        rcv.clear();
        int byteRecived = 0;

            byteRecived = read(a, buffer.data(), buffer.size());
            if (byteRecived == -1) {
                cout << "Error reading rowCordination" << endl;
                exit(-1);
            } else {
                rcv.append(buffer.begin(), buffer.end());
            }
        int s = rcv.find('<');
        int y = rcv.size();
        int i=0;
        for(i=0;i<rcv.size();i++){
            if(rcv.at(i)==NULL){
                break;
            }
        }
        string command = rcv.substr(0, i);
        loop = rcv.substr(0, s);

        CommandManager manager;
        manager.executeCommand(command, a);
    }

}

