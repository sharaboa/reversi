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
#include "ThreadPool.h"


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
    static void *connect(void *s);
    /**
     * stop the server - closing all opened threads
     */
    void stop();
    /**
     * return thread pool by reference
     * @return
     */
    ThreadPool& getPool() ;
    /**
     * return server socket
     * @return
     */
    long getServerSocket();

private:

    int port;
    long serverSocket; // the socket's file descriptor
    pthread_t serverThreadId;
    ThreadPool threadPool;
};

#endif //SERVER_SERVER_H