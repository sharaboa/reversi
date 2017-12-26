//
// Created by or on 21/12/17.
//

#include "JoinCommand.h"


JoinCommand::JoinCommand(vector <Game> gamesList) {}

void JoinCommand::execute(string args, int clientSocket) {
    string player;
    for (int i = 0;i<gamesList.size();i++)
        if((!(gamesList.at(i).oSocket)) && (args.compare(gamesList.at(i).gameName) == 0 )) {
            gamesList.at(i).oSocket = clientSocket;
            string player = "You are X and the first one to play";
            int n = write(clientSocket, &player, sizeof(player));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            player = "You are Y and the second one to play";
            n = write(clientSocket, &player, sizeof(player));
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