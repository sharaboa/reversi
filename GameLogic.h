//
// Or Sharabi 312530496
// Created by or on 01/11/17.
//

#ifndef EX2_GAMELOGIC_H
#define EX2_GAMELOGIC_H


#include "Board.h"
#include "Player.h"
#include <string>
#include <cstring>

using namespace std;

class GameLogic {
public:
    /**
     * constructor. gets reference to the matrix board.
     * @param board
     */
    explicit GameLogic(Board &board);
    /**
     * Updating the stack to contain the places where the winning player can put a disc
     * @param winning - current player's form
     * @param loosing - stack of the opponent
     */
    void options(const char &winning,const Player &loosing);

    /**
     * Updating the board and the players status following the move of the winning player
     * @param winning - current player's stack
     * @param loosing - opponent's stack
     */
    void eat(Player &winning, Player &loosing);
    /**
     * manages winning player's turn
     * @param winning - current player
     * @param loosing - opponent player
     */
    void turn(Player &winning, Player &loosing);
    /**
     * Gets a location on the board from the user and translates it to disc
     * @param input - string the user typed
     * @return - the asked disc
     */
    Disc fromStringToDisc(char input[50]);
    /**
     * Prints a note that the player has no moves
     * @param winning - current player's form
     * @param loosing - opponent playerws form
     */
    void noTurn(const char &winning,const char &loosing);
    /**
     * Returns the number of options available to the current player
     * @return
     */
    int hasMoves() const;

private:
    Board &board;
    StackOfDiscs emptyCellStack;
    Disc emptyCell;
};

#endif //EX2_GAMELOGIC_H
