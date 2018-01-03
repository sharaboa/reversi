//
// Created by or on 23/12/17.
//

#ifndef REVERSI_SCREENVIEW_H
#define REVERSI_SCREENVIEW_H

#include <iostream>
#include "Board.h"
#include "StackOfDiscs.h"

using namespace std;

class ScreenView {
public:
    /**
     * constructor - prints on screen.
     */
    ScreenView();
    /**
     * asking to choose player type and prints error for illegal choice
     * @param choice - true if the input legal and false otherwise
     */
    void printMenu(bool choice) const;
    /**
     * prints the board
     * @param board - current board
     */
    void printBoard(Board &board) const;
    /**
     * asking for move
     * @param optionStack - to present the player's option moves
     * @param currentPlayer - the symbol of current player
     * @param choice - the chosen move
     */
    void printEnterMove(StackOfDiscs &optionStack, Symbol currentPlayer,int choice) const;
    /**
     * prints the status of player
     * @param connection - player's status
     */
    void printClientConnection(int connection) const;
    /**
     * prints the board and player choice after making a move
     * @param board - current board after choice
     * @param playerChoice - the choice
     * @param player - the player that played
     */
    void printMove(Board &board, Disc &playerChoice, Symbol player) const;
    /**
     * announce the winner
     * @param player1 - symbol of one of the players
     * @param player2 - symbol of second player
     * @param amountPlayer1 - the amount of disc the player putted on board
     * @param amountPlayer2 - the amount of disc the player putted on board
     */
    void announceWinner(Symbol player1,Symbol player2,int amountPlayer1,int amountPlayer2) const;
    /**
     * print asked string
     * @param output 
     */
    void coutToScreen(string output) const;
    /**
     * menu of remote player
     */
    void remotePlayerMenu() const;
    /**
     * print if game opened or not
     * @param valid - -1 if not open
     */
    void printStartCommand(int valid) const;
    /**
     * exit of server
     */
    void printServerDisconect() const;
};

#endif //REVERSI_SCREENVIEW_H