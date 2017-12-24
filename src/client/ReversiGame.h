//
// Or Sharabi 312530496
//Sahar levi 203405147
//
#ifndef EX2_REVERSIGAME_H
#define EX2_REVERSIGAME_H


#include <string>
#include <cstring>
#include "Board.h"
#include "Player.h"
#include "GameLogic.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"

using namespace std;

class ReversiGame {
public:
    /**
     * constructor. Initializes board
     * @param size - of board
     * @param black - first player
     * @param white - second player
     */

    ReversiGame(int size);

    /**
     * Initializes the board and players by placing two discs per player in the center of the board
     * @param black  - x player
     * @param white  - o player
     * @param board
     */
    void initialize (Player *black, Player *white, Board &board);
    /**
     * build 2 humans players
     * @param b - x
     * @param w - o
     */
    void manageHuman(Symbol b, Symbol w);
    /**
     * build human and ai player
     * @param b - x
     * @param w - o
     */
    void manageAi(Symbol b, Symbol w);
    /**
     * build 2 players on the same port
     * reading for file the port and ip
     * @param b - x
     * @param w - o
     */
    void manageRemoteGame(Symbol b, Symbol w);
    /**
     * manage the turns of the 2 players
     * @param current - current player
     * @param opponent - other player
     */
    void play(Player *current,Player *opponent);

protected:
    Board board;
    GameLogic gameLogic;
    const int size;
    ScreenView screenView;
};


#endif //EX2_REVERSIGAME_H