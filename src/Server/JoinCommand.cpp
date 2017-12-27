//
// Created by sahar on 26/12/17.
//

#include "JoinCommand.h"

JoinCommand::JoinCommand(const vector <Game> &gamesList): gamesList(gamesList) {}

void JoinCommand::execute(string args, int clientSocket) {
    string player;
    for (int i = 0;i<gamesList.size();i++)
        if((!(gamesList.at(i).oSocket)) && (args.compare(gamesList.at(i).gameName) == 0 )) {
            gamesList.at(i).oSocket = clientSocket;
            int player = 1;
            int n = write( gamesList.at(i).xSocket, &player, sizeof(player));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            player = 2;
            n = write( gamesList.at(i).oSocket, &player, sizeof(player));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
        }
    if(!player.size()) {
        player = "You can not join this game. Please coose another one";
        int n = write(clientSocket, &player, sizeof(player));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
        }
    }
}