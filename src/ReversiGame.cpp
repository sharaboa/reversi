//
// Or Sharabi 312530496
// Created by or on 02/11/17.
//

#include <iostream>
#include "ReversiGame.h"

ReversiGame::ReversiGame(int size): board(size),gameLogic(board),size(size) {}


void ReversiGame::initialize(Symbol b,Symbol w,char x) {
    Player *const black = new HumanPlayer(b);
    Player *white;
    switch (x) {
        case 'c': case 'C': {
            white = new AiPlayer(w,gameLogic,board);
            break;
        }
        case 'h': case 'H': {
            white = new HumanPlayer(w);
        }
    }
    int midSize = size / 2;
    board.fillMatrixBoard(midSize,black->getSymbol(),white->getSymbol());
    white->addToStack(midSize + 1,midSize + 1);
    white->addToStack(midSize, midSize);
    black->addToStack(midSize, midSize + 1);
    black->addToStack(midSize + 1,midSize);
    play(black,white);
    delete black;
    delete white;
}

void ReversiGame::play(Player *black,Player *white) {
    //notOver zeroed when both players have no moves
    int notOver = 2;
    cout << "current board:\n";
    board.printBoard();
    while(notOver && black->getAmount() + white->getAmount() != size*size) {
        black->playerMoveOption(*white ,board);
        if (gameLogic.hasMoves(*black)) {
            notOver = 2;
            gameLogic.turn(*black, *white, black->playerLogic(*white));
        } else {
            notOver--;
            if(notOver) {
                cout << (char)black->getSymbol() << ": It's your move.\nNo possible moves. Play passes back to the othe player.\n\n\n";

            }
        }
        if(notOver && black->getAmount() + white->getAmount() != size*size) {
            white->playerMoveOption(*black ,board);
            if (gameLogic.hasMoves(*white)) {
                notOver = 2;
                gameLogic.turn(*white, *black,white->playerLogic(*black));

            } else {
                notOver--;
                if(notOver) {
                    cout << (char)white->getSymbol() << ": It's your move.\nNo possible moves. Play passes back to the othe player.\n\n\n";
                }
            }
        }
    }
    announceWinner(black,white);
}

void ReversiGame::announceWinner(Player *black,Player *white) const {
    if (black->getAmount() == white->getAmount()) {
        cout << "Game Over! it's a tie " << endl;
    } else {
        black->getAmount() > white->getAmount() ?
        cout << "Game Over! the winner is: " << (char)black->getSymbol() :
        cout << "Game Over! the winner is: " << (char)white->getSymbol();
    }
}