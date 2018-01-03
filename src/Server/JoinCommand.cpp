//
// Created by sahar on 26/12/17.
//

#include "JoinCommand.h"
#include "PlayCommand.h"

JoinCommand::JoinCommand() {}

void JoinCommand::execute(string args, int clientSocket) {
    int player = -1;
    for (int i = 0;i<getGameList()->getGamesList().size();i++)
        if(((getGameList()->getGamesList().at(i).oSocket) == -2) && (args.compare(getGameList()->getGamesList().at(i).gameName) == 0 )) {
            getGameList()->setGame(i,clientSocket);
            int xSocket =getGameList()->getGamesList().at(i).xSocket;
            int oSocket = getGameList()->getGamesList().at(i).oSocket;
            player = 1;
            int n = write(clientSocket, &player, sizeof(player));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            n = write(xSocket, &player, sizeof(player));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            player = 2;
            n = write(oSocket, &player, sizeof(player));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }

            getGameList()->removeGame(i);
            PlayCommand play(xSocket,oSocket);
        }
    if(player == -1) {
        int n = write(clientSocket, &player, sizeof(player));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
        }
    }
}