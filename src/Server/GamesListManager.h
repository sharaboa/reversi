//
// Created by or on 28/12/17.
//

#ifndef REVERSI_GAMESLISTMANAGER_H
#define REVERSI_GAMESLISTMANAGER_H


#include <vector>
#include "GameStruct.h"

class GamesListManager {
public:
    static GamesListManager *getInstance();
    void addGame(Game game);
    void removeGame(string name);
    void setGame(int i, int oSocket);
    vector<Game> getGamesList() const;
private:
    vector<Game> gamesList;
    GamesListManager(): gamesList() {};
    GamesListManager(const GamesListManager &other);
    ~GamesListManager() {};
    static GamesListManager *instance;
};


#endif //REVERSI_GAMESLISTMANAGER_H
