//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <iostream>
#include <cstdlib>
#include "Server.h"
#include "CommandManager.h"
using namespace std;
int main() {

   /* GamesListManager *sc1,*sc2, *sc3;
    sc1 = GamesListManager::getInstance();
    Game game1;
    game1.gameName = "or";
    sc1->addGame(game1);
    sc2 = GamesListManager::getInstance();
    Game game2;
    game2.gameName = "sharabi";
    sc2->addGame(game2);
    vector<Game> f = sc2->getGamesList();
    sc3 = GamesListManager::getInstance();
    sc3->removeGame(game2.gameName);
    f = sc2->getGamesList();
*/

    Server server;

    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}