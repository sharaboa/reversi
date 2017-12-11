//
// Or Sharabi 312530496
//Sahar levi 203405147
//
#ifndef EX2_GAMELOGIC_H
#define EX2_GAMELOGIC_H


#include "Board.h"
#include "Player.h"
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

class GameLogic {
public:
    /**
     * constructor. gets reference to the matrix board.
     * @param board
     */
    explicit GameLogic(Board &board);

    /**
     * checks how board and the players status looks like after move of current player
     * @param currentPlayer - current player's stack
     * @param opponentPlayer - opponent's stack
     */
    vector<Player> eat(Player currentPlayer, Player opponentPlayer,Disc playerChoise, Board &tempBoard);
    /**
     * manages player's turn
     * @param currentPlayer - current player
     * @param opponentPlayer - opponent player
     */
    void turn(Player &currentPlayer, Player &opponentPlayer,Disc playerChoise);

    /**
     * Returns the number of options available to the current player
     * @return number of moves (with dublications)
     */
    int hasMoves(Player &currentPlayer) const;
    /**
     * Updating the board and the players status following the move of current player
     * @param tempPlayers - vector contain the stacks of players that need to be update
     * @param currentPlayer - current player before move
     * @param opponentPlayer - opponent player before move
     * @param playerChoise - current player choise of disc
     */
    void updateMove(const vector<Player> &tempPlayers, Player &currentPlayer, Player &opponentPlayer,Disc &playerChoise);

private:
    Board &board;
};

#endif //EX2_GAMELOGIC_H
