//
// Created by sahar on 27/12/17.
//

#include <cstring>
#include "ListOfGamesCommand.h"
#include "ScreenView.h"

ListOfGamesCommand::ListOfGamesCommand() {}

void ListOfGamesCommand::execute(string input, int clientSocket) {
    int n = write(clientSocket, input.c_str(), input.length());
    if (n == -1) {
        throw "Error writing arg1to socket";
    }

    int numOfGames;

    /////////////////   if not use int
    n = read(clientSocket, &numOfGames, sizeof(numOfGames));
    if (n == -1) {
        throw "Error writing arg1to socket";
    }
    ScreenView myView;

    if(numOfGames == 0 ){
        myView.coutToScreen("No availabel game, Pls open a new one");
    }
    for (int j = 0; j < numOfGames ; j++) {
        vector<char> buffer(4096);
        string rcv;
        int byteRecived = 0;

        byteRecived = read(clientSocket, buffer.data(), buffer.size());
        if (byteRecived == -1) {
            cout << "Error reading rowCordination" << endl;
            exit(-1);
        } else {
            rcv.append(buffer.begin(), buffer.end());
        }
        int i=0;
        for(i=0;i<rcv.size();i++){
            if(rcv.at(i)==NULL){
                break;
            }
        }
        myView.coutToScreen(rcv.substr(0, i));
        cout<<endl;
    }

}
