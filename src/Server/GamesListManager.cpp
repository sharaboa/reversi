//
// Created by or on 28/12/17.
//

#include "GamesListManager.h"

//GamesListManager::GamesListManager(): gamesList(vector<Game>(0)) {}
void GamesListManager::addGame(Game game) {
    gamesList.push_back(game);
}
void GamesListManager::removeGame(int i) {
    gamesList.erase(gamesList.begin() + i);

}
void GamesListManager::setGame(int i, int oSocket) {
    gamesList[i].oSocket = oSocket;
}
vector<Game> GamesListManager::getGamesList() const {
    return gamesList;
}

GamesListManager *GamesListManager::instance = 0;
pthread_mutex_t GamesListManager::lock;

GamesListManager *GamesListManager::getInstance() {
    if (instance == 0) {
        pthread_mutex_lock(&lock);
        if (instance == 0){
            instance = new GamesListManager;
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}