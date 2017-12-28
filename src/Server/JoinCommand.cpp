//
// Created by sahar on 26/12/17.
//

#include "JoinCommand.h"

JoinCommand::JoinCommand() {}

void JoinCommand::execute(string args, int clientSocket) {
    string player;
    for (int i = 0;i<this->getGamesList().size();i++)
        if((!(this->getGamesList().at(i).oSocket)) && (args.compare(this->getGamesList().at(i).gameName) == 0 )) {
            this->getGamesList().at(i).oSocket = clientSocket;
            int player = 1;
            int n = write( this->getGamesList().at(i).xSocket, &player, sizeof(player));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            player = 2;
            n = write(this->getGamesList().at(i).oSocket, &player, sizeof(player));
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