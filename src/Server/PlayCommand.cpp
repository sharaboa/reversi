//
// Created by or on 21/12/17.
//

#include <string>
#include <iostream>
#include <cstdlib>
#include "PlayCommand.h"

/*struct Output{
    int row;
    int col;
} out;*/

PlayCommand::PlayCommand(vector <Game> gamesList) {}

void PlayCommand::execute(string args, int clientSocket) {
    int i = args.find(',');
    string r = args.substr(0,i);
    string c = args.substr(i+1);
    int row = atoi(r.c_str());
    int col = atoi(c.c_str());

    for(int i = 0; i < gamesList.size(); i++) {
        if(gamesList.at(i).oSocket == clientSocket) {
            int n = write(clientSocket, &row, sizeof(row));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            n = write(clientSocket, &col, sizeof(col));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            break;
        }
        if(gamesList.at(i).xSocket == clientSocket) {
            int n = write(clientSocket, &row, sizeof(col));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            n = write(clientSocket, &col, sizeof(row));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            break;
        }
    }
}