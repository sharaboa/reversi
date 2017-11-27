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
     * Updating the stack to contain the places where the winning player can put a disc
     * @param currentPlayer - current player's form
     * @param opponentPlayer - stack of the opponent
     */
   // void options(const Player &opponentPlayer,Board board);

    /**
     * Updating the board and the players status following the move of the winning player
     * @param currentPlayer - current player's stack
     * @param opponentPlayer - opponent's stack
     */
    vector<Player> eat(Player currentPlayer, Player opponentPlayer,Disc playerChoise, Board &tempBoard);
    /**
     * manages winning player's turn
     * @param currentPlayer - current player
     * @param opponentPlayer - opponent player
     */
    void turn(Player &currentPlayer, Player &opponentPlayer,Disc playerChoise);
  /*  *//**
     * Gets a location on the board from the user and translates it to disc
     * @param input - string the user typed
     * @return - the asked disc
     *//*
    Disc fromStringToDisc(char input[50]);*/
    /**
     * Returns the number of options available to the current player
     * @return
     */
    int hasMoves(Player &currentPlayer) const;
    void updateMove(const vector<Player> &tempPlayers, Player &currentPlayer, Player &opponentPlayer,Disc &playerChoise);

private:
    Board &board;
   // StackOfDiscs stackOfOptions;
   // Disc playerChoise;
};

#endif //EX2_GAMELOGIC_H
