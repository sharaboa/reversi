//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <unistd.h>
#include <netinet/in.h>
#include <vector>
#include "GameStruct.h"
#include "CommandManager.h"


class Server {

public:
    /**
     * constructor
     * @param port
     */
    Server();
    /**
     * running the game
     */
    void start();

    /**
     * connect players and sending 1 to first player and 2 for second
     * @param clientAddress
     * @param clientAddressLen
     */
    static void *connect(void *args);

    /**
     * sending to each other the chosen disc
     *  0,0 if there is no move
     *  -2,-2 if the game is over
     * @param clientSocket - current player
     * @param clientSocket2 - opponent player
     * @return - false if game continue and true otherwise(game over)
     */
    bool handleClient(int clientSocket) ;
    vector <Game> getList();
    void writeToClient (int clientSoket,struct Output &out);
    void readToClient();
    void closeGame(Game game);
    void exitThreads();
private:

    int port;
    //static int serverSocket;

    vector <pthread_t> threadsList;
    vector <int> socketsList;
    CommandManager myManager;

};

#endif //SERVER_SERVER_H