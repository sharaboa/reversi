//
// Or Sharabi 312530496
// Created by or on 25/10/17.
//

#include "Board.h"
#include <iostream>



Board::Board(const int size): size(size){
    buildMatrixBoard();
}

void Board::buildMatrixBoard() {
    matrixBoard = new Symbol*[size];
    for(int i = 0; i < size; i++) {
        matrixBoard[i] = new Symbol[size];
    }
}

void Board::fillMatrixBoard(const int &midSize,Symbol black,Symbol white) {
    //puts the player's discs in the middle of the matrix
    matrixBoard[midSize][midSize] = white;
    matrixBoard[midSize - 1][midSize] = black;
    matrixBoard[midSize][midSize - 1] = black;
    matrixBoard[midSize - 1][midSize - 1] = white;
    //puts spaces in rest of the matrix
    for (int i = 1; i < size - 1; i++) {
        for(int j = 1; j < size - 1; j++) {
            if (matrixBoard[i][j] != black && matrixBoard[i][j] != white) {
                matrixBoard[i][j] = S;
            }
        }
    }
    //puts $ in the borderlines of the matrix
    for(int i = 0; i < size; i++) {
        matrixBoard[0][i] = B;
        matrixBoard[i][0] = B;
        matrixBoard[size - 1][i] = B;
        matrixBoard[i][size - 1] = B;
    }
}

void Board::printBoard() const {
    //prints number by line and column
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1; j++) {
            if (i == 0 && j == 0) {
                cout << " | ";
            } else {
                if (i == 0 && j > 0) {
                    cout << j << " | ";
                } else {
                    if (j == 0 && i > 0) {
                        cout << i << "| ";
                    } else {
                        cout << (char)matrixBoard[i][j] << " | ";
                    }
                }
            }
        }
        //prints lines separates lines
        cout << endl << "--";
        for(int k = 0; k < (size - 2) * 4; k++) {
            cout << "-";
        }
        cout << endl;
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
    otherBoard.buildMatrixBoard();
    for(int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            otherBoard.setCell(i, j, matrixBoard[i][j]);
        }
    }
}
int Board::getSize() const {
    return size;
}

Board Board::getBoard() const {
    return *this;
}

