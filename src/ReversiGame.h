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
    //void manage(Symbol b, Symbol w, char x);
    /**
     * The game manager. decides who turn to play and returns the winner
     */
    //virtual void play(Player *black,Player *white) = 0;

    /**
     * this fun announce the winner/a tie
     * @return the form of the winner
     */
    void announceWinner(Player *black,Player *white) const;
    void initialize (Player *black, Player *white, Board &board);
    void manageHuman(Symbol b, Symbol w);
    void manageAi(Symbol b, Symbol w);
    void manageRemoteGame(Symbol b, Symbol w);
    void play(Player *current,Player *opponent);
    //void playClient(Player *currentPlayer,Player *opponentPlayer);
    // void manageHuman(Symbol b, Symbol w);
    // void manageAi(Symbol b, Symbol w);
    //void manageClient(Symbol b, Symbol w);

protected:
    Board board;
    GameLogic gameLogic;
    const int size;
};


#endif //EX2_REVERSIGAME_H