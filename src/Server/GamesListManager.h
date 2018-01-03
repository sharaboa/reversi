//
// Created by or on 28/12/17.
//

#ifndef REVERSI_GAMESLISTMANAGER_H
#define REVERSI_GAMESLISTMANAGER_H


#include <vector>
#include "GameStruct.h"

class GamesListManager {
public:
    /**
     * creating a singelton pattern class to keep a list of all the current oppened games
     * @return the class itself if exist otherwise create a new one
     */
    static GamesListManager *getInstance();
    /**
     *
     * @param game the game name to add to the vector
     */
    void addGame(Game game);
    /**
     * removing the i game from the vector
     * @param i the game index
     */
    void removeGame(int i);
    /**
     * seting a new game
     * @param i the index
     * @param oSocket the 2 player socket
     */
    void setGame(int i, int oSocket);
    /**
     * @return the vector holding the games
     */
    vector<Game> getGamesList() const;
private:
    vector<Game> gamesList;
    GamesListManager(): gamesList() {};
    GamesListManager(const GamesListManager &other);
    ~GamesListManager() {};
    static GamesListManager *instance;
    static pthread_mutex_t lock;
};


#endif //REVERSI_GAMESLISTMANAGER_H