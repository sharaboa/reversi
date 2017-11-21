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

using namespace std;

class ReversiGame {
public:
    /**
     * constructor. Initializes board and players
     * @param size - of board
     * @param black - first player
     * @param white - second player
     */
    ReversiGame(int size,char black,char white);
    /**
     * constructor. difault - initialize 8x8 board and x,o players
     */
    ReversiGame();
    /**
     * Initializes the board and players after placing two discs per player in the center of the board
     * @param board
     * @param black - x player
     * @param white - o player
     */
    void initialize(Board &board, Player &black, Player &white);
    /**
     * The game manager. decides who turn to play and returns the winner
     * @return
     */
    char play();

    /**
     * Returns the form of the winner
     * @return
     */
    char getWinner() const;


private:
    Board board;
    Player black;
    Player white;
    GameLogic gameLogic;
    const int size;
};


#endif //EX2_REVERSIGAME_H