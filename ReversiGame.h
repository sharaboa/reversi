//
// Or Sharabi 312530496
// Created by or on 02/11/17.
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
    //ReversiGame(int size,const char b,const char w,char x);
    /**
     * constructor. Initializes board and players
     * @param size - of board
     * @param black - first player
     * @param white - second player
     */

    //ReversiGame(const int size);

    //ReversiGame(const int size, const Player &b, const Player &w);


    ReversiGame(int size);

    /**
                         * Initializes the board and players after placing two discs per player in the center of the board
                         * @param board
                         * @param black - x player
                         * @param white - o player
                         */
    void initialize(char b,char w,char x);
    /**
     * The game manager. decides who turn to play and returns the winner
     * @return
     */
    char play(Player *black,Player *white);

    /**
     * Returns the form of the winner
     * @return
     */
    void announceWinner(Player *black,Player *white) const;


private:
    Board board;
   // Player *white;
   // Player *black;
    GameLogic gameLogic;
    const int size;
    char hOrc;
};


#endif //EX2_REVERSIGAME_H