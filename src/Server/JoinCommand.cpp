//
// Created by or on 21/12/17.
//

#include "JoinCommand.h"

/*struct Output{
    string player;
} out;*/

JoinCommand::JoinCommand(vector <Game> gamesList) {}
//JoinCommand::JoinCommand(Server &server) {}

void JoinCommand::execute(string args, int clientSocket) {
    string player;
    for (int i = 0;i<gamesList.size();i++)
        if((!(gamesList.at(i).oSocket)) && (args.compare(gamesList.at(i).gameName) == 0 )) {
            gamesList.at(i).oSocket = clientSocket;
            //out.player = "You are X and the first one to play";
            //server.writeToClient(server.getList().at(i).xSocket,out);
            string player = "You are X and the first one to play";
            int n = write(clientSocket, &player, sizeof(player));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
            player = "You are Y and the second one to play";
            //out.player = "You are Y and the second one to play";
            //server.writeToClient(clientSocket,out);
            n = write(clientSocket, &player, sizeof(player));
            if (n == -1) {
                cout << "Error writing to socket" << endl;
            }
        }
    if(!player.size()) {
        //out.player = "You can not join this game. Please coose another one";
        //server.writeToClient(clientSocket,out);
        player = "You can not join this game. Please coose another one";
        int n = write(clientSocket, &player, sizeof(player));
        if (n == -1) {
            cout << "Error writing to socket" << endl;
        }

    }
}