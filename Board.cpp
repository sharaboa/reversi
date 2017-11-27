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
    matrixBoard = new boardSymbol*[size];
    for(int i = 0; i < size; i++) {
        matrixBoard[i] = new boardSymbol[size];
    }
}

void Board::fillMatrixBoard(const int &midSize,const char &black,const char &white) {
    //puts the player's discs in the middle of the matrix
    matrixBoard[midSize][midSize] = (boardSymbol) white;
    matrixBoard[midSize - 1][midSize] = (boardSymbol) black;
    matrixBoard[midSize][midSize - 1] = (boardSymbol) black;
    matrixBoard[midSize - 1][midSize - 1] = (boardSymbol) white;
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
        delete[]matrixBoard[i];
    }
    if (*matrixBoard)
        delete[] matrixBoard;
}

char Board::getCell(const int &i,const int &j) const {
    return matrixBoard[i][j];
}

void Board::setCell(const int &i, const int &j, const char &win) {
    matrixBoard[i][j] = (boardSymbol) win;
}

void Board::setBoard(Board otherBoard) {
    for(int i = 0; i < size; i++) {
        for(int j = 0;j < size; j++) {
            matrixBoard[i][j] = static_cast<boardSymbol>(otherBoard.getCell(i, j));
        }
    }
}
void Board::copyBoard(Board &otherBoard){
    otherBoard.buildMatrixBoard();
    for(int i = 0; i < size; i++) {
        for(int j = 0;j < size; j++) {
            // cout<<"orig"<<matrixBoard[i][j]<<"  ";
            otherBoard.setCell(i,j,matrixBoard[i][j]);
            // cout<<"other"<<otherBoard.getCell(i,j)<<endl;
        }
    }
    cout<<"other board"<<endl;
    otherBoard.printBoard();
}
int Board::getSize() const {
    return size;
}

Board Board::getBoard() const {
    return *this;
}

