//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#ifndef REVERSI_CLIENT_H
#define REVERSI_CLIENT_H


#include "Player.h"
#include "HumanPlayer.h"
#include "ScreenView.h"

class ClientPlayer : public HumanPlayer {
public:
    /**
     * constructor of remote player.
     * @param symbol -of disc of ClientPlayer
     * @param serverIP - ip
     * @param serverPort  - port
     */
    ClientPlayer(Symbol symbol,const char *serverIP, int serverPort);

    /**
     * play turn and sending the move to the other player
     * update other player move
     * @param opponentPlayer
     * @return
     */
    virtual Disc playerLogic(Player opponentPlayer);
    /**
     * connectToServer
     */
    void connectToServer();
    /**
     * clientNum in order to identify whitch player's turn
     * @return 1-x/2-o
     */
    int getClientNum();
    /**
     * ClientSocket in order to open two players on the same socket each computer
     * @return socket
     */
    int getClientSocket();
    /**
     * clientNum - 1 if I am x and 2 if I am o
     * @param myClientNum
     */
    void setClientNum(int myClientNum);
    /**
     * updating Socket
     * @param myClientSocket
     */
    void setClientSocket(int myClientSocket);
    /**
     * updating myChoise as (0,0) disc to sign that the player has no moves
     */
    void notMove();
    /**
     * updating myChoise as (-2,-2) disc to sign that the game is over
     */
    void gameOver();
    void readClientNum();
    string readFromServer();
    void writeToServer(string command);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    int clientNum;
    ScreenView screenView;
};



#endif //REVERSI_CLIENT_H