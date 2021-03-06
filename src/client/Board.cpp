//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include "Board.h"


Board::Board(const int size): size(size+2){
    buildMatrixBoard();
}

void Board::buildMatrixBoard() {
    matrixBoard = new Symbol*[size];
    for(int i = 0; i < size; i++) {
        matrixBoard[i] = new Symbol[size];
    }
}

void Board::fillMatrixBoard(const int &midSize,Symbol black,Symbol white) {
    //puts spaces in rest of the matrix
    for (int i = 1; i < size - 1; i++) {
        for(int j = 1; j < size - 1; j++) {
            matrixBoard[i][j] = S;
        }
    }
    //puts the player's discs in the middle of the matrix
    matrixBoard[midSize + 1][midSize + 1] = white;
    matrixBoard[midSize][midSize + 1] = black;
    matrixBoard[midSize + 1][midSize] = black;
    matrixBoard[midSize][midSize] = white;

    //puts $ in the borderlines of the matrix
    for(int i = 0; i < size; i++) {
        matrixBoard[0][i] = B;
        matrixBoard[i][0] = B;
        matrixBoard[size - 1][i] = B;
        matrixBoard[i][size - 1] = B;
    }
}

Board::~Board() {
    for (int i = 0; i < size; i++) {
        delete[] matrixBoard[i];
    }
    delete[] matrixBoard;
}

Symbol Board::getCell(const int &i,const int &j) const {
    return matrixBoard[i][j];
}

void Board::setCell(const int &i, const int &j, Symbol player) {
    matrixBoard[i][j] = player;
}

void Board::copyBoard(Board &otherBoard){
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            otherBoard.setCell(i, j, matrixBoard[i][j]);
        }
    }
}

int Board::getSize() const {
    return size - 2;
}