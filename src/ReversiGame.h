//
// Or Sharabi 312530496
//Sahar levi 20340514
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
     * constructor. Initializes board and players
     * @param size - of board
     * @param black - first player
     * @param white - second player
     */

    ReversiGame(int size);

    /**
     * Initializes the board and players after placing two discs per player in the center of the board
     * @param board
     * @param black - x player
     * @param white - o player
     */
    void initialize(Symbol b,Symbol w,char x);
    /**
     * The game manager. decides who turn to play and returns the winner
     * @return
     */
    void play(Player *black,Player *white);

    /**
     * Returns the form of the winner
     * @return
     */
    void announceWinner(Player *black,Player *white) const;


private:
    Board board;
    GameLogic gameLogic;
    const int size;
};


#endif //EX2_REVERSIGAME_H