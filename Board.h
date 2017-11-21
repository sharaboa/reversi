//
// Or Sharabi 312530496
// Created by or on 25/10/17.
//

#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include <string>
#include "Disc.h"
#include "Player.h"

using namespace std;


class Board {
public:
    /**
     * constructor. getting the board size
     * @param size - size of the board
     */
    explicit Board(int size);
    /**
     * builds the matrix of the game board.
     */
    void buildMatrixBoard();
    /**
     * initialize the board.
     * @param midSize - middle of the board
     * @param black - black player's form
     * @param white - white player's form
     */
    void fillMatrixBoard(const int &midSize,const char &black,const char &white);
    /**
     * prints the board.
     */
    void printBoard() const;
    /**
     * destructor.
     */
    ~Board();
    /**
     * returns asked place in the board
     * @param i - row
     * @param j - column
     * @return the form in the cell.
     */
    char getCell(const int &i, const int &j) const;

    /**
     * Updating disc in the board
     * @param i - row
     * @param j - column
     * @param win - the form that enters the board
     */
    void setCell(const int &i, const int &j, const char &win) const;

private:
    const int size;
    char** matrixBoard;
};


#endif //EX2_BOARD_H