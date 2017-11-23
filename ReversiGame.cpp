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
        black.playerMoveOption(white ,board);
        if (gameLogic.hasMoves(black)) {
            notOver = 2;
            gameLogic.turn(black, white,black.playerLogic());
        } else {
            notOver--;
            if(notOver) {
                cout << black.getForm() << ": It's your move.\nNo possible moves. Play passes back to the othe player.\n\n\n";

            }
        }
        if(notOver && black.getAmount() + white.getAmount() != size*size) {
            white.playerMoveOption(black ,board);
            if (gameLogic.hasMoves(white)) {
                notOver = 2;
                gameLogic.turn(white, black,white.playerLogic());
            } else {
                notOver--;
                if(notOver) {
                    cout << white.getForm() << ": It's your move.\nNo possible moves. Play passes back to the othe player.\n\n\n";
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