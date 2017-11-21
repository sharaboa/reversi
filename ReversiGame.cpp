//
// Or Sharabi 312530496
// Created by or on 02/11/17.
//

#include <iostream>
#include "ReversiGame.h"

ReversiGame::ReversiGame(): board(10),black('X'),white('O'), gameLogic(board),size(8){
    initialize(board,black,white);
}

ReversiGame::ReversiGame(const int size,const char b,const char w):
        board(size + 2),black(b),white(w),gameLogic(board),size(size){
    initialize(board,black,white);
}

void ReversiGame::initialize(Board &board, Player &black, Player &white) {
    int midSize = (size + 2) / 2;
    board.fillMatrixBoard(midSize,black.getForm(),white.getForm());
    white.addToStack(midSize,midSize);
    white.addToStack(midSize - 1, midSize - 1);
    black.addToStack(midSize - 1, midSize);
    black.addToStack(midSize,midSize - 1);
}

char ReversiGame::play() {
    //notOver zeroed when both players have no moves
    int notOver = 2;
    cout << "current board:\n\n";
    board.printBoard();
    while(notOver && black.getAmount() + white.getAmount() != size*size) {
        gameLogic.options(black.getForm(),white);
        if (gameLogic.hasMoves()) {
            notOver = 2;
            gameLogic.turn(black, white);
        } else {
            notOver--;
            if(notOver) {
                gameLogic.noTurn(white.getForm(), black.getForm());
            }
        }
        if(notOver && black.getAmount() + white.getAmount() != size*size) {
            gameLogic.options(white.getForm(),black);
            if (gameLogic.hasMoves()) {
                notOver = 2;
                gameLogic.turn(white, black);
            } else {
                notOver--;
                if(notOver) {
                    gameLogic.noTurn(black.getForm(), white.getForm());
                }
            }
        }
    }
    char winner = getWinner();
    return winner;
}


char ReversiGame::getWinner() const {
    if (black.getAmount() == white.getAmount()) {
        return ' ';
    }
    return black.getAmount() > white.getAmount() ? black.getForm() : white.getForm();
}