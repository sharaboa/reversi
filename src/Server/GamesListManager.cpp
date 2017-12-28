//
// Created by or on 28/12/17.
//

#include "GamesListManager.h"

//GamesListManager::GamesListManager(): gamesList(vector<Game>(0)) {}
void GamesListManager::addGame(Game game) {
    gamesList.push_back(game);
}
void GamesListManager::removeGame(string name) {
    for(int i = 0; i <= gamesList.size(); i++) {
        if (gamesList[i].gameName.compare(name)) {
            gamesList.erase(gamesList.begin() + i + 1);
            break;
        }
    }
}
void GamesListManager::setGame(int i, int oSocket) {
    gamesList[i].oSocket = oSocket;
}
vector<Game> GamesListManager::getGamesList() const {
    return gamesList;
}
GamesListManager *GamesListManager::instance = 0;
GamesListManager *GamesListManager::getInstance()
{
    if (instance == 0) {
        instance = new GamesListManager;
    }
    return instance;
}