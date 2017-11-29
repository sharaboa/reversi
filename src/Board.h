//
// Or Sharabi 312530496
//Sahar levi 203405147
//
#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include "Board.h"
#include <string>
#include <vector>
#include "Disc.h"
#include "Symbol.h"

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
    void fillMatrixBoard(const int &midSize,Symbol black,Symbol white);
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
    Symbol getCell(const int &i, const int &j) const;

    /**
     * Updating disc in the board
     * @param i - row
     * @param j - column
     * @param win - the form that enters the board
     */
    void setCell(const int &i, const int &j, Symbol player);

   // void setBoard(Board board);

    int getSize() const;

    Board getBoard() const;
    void  copyBoard(Board &otherBoard);

private:
    const int size;
    Symbol** matrixBoard;
    //vector< vector<char> > matrixBoard;
};

#endif //EX2_BOARD_H