//
// Or Sharabi 312530496
// Created by or on 02/11/17.
//

#include <iostream>
#include "ReversiGame.h"

ReversiGame::ReversiGame(int size): board(size + 2),gameLogic(board),size(size) {
    /*Player *black = new HumanPlayer(b);
    Player *white;

    switch (x) {
            case 'c': case 'C': {
                white = new AiPlayer(w,gameLogic,board);
                break;
            }
            case 'h': case 'H': {
                white = new HumanPlayer(w);
            }
        }*/
   // initialize(black,white);
}


void ReversiGame::initialize(char b,char w,char x) {
    Player *black = new HumanPlayer(b);
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
    int midSize = (size + 2) / 2;
    board.fillMatrixBoard(midSize,black->getForm(),white->getForm());
    white->addToStack(midSize,midSize);
    white->addToStack(midSize - 1, midSize - 1);
    black->addToStack(midSize - 1, midSize);
    black->addToStack(midSize,midSize - 1);
    play(black,white);
}

char ReversiGame::play(Player *black,Player *white) {
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
                cout << black->getForm() << ": It's your move.\nNo possible moves. Play passes back to the othe player.\n\n\n";

            }
        }
        if(notOver && black->getAmount() + white->getAmount() != size*size) {
            white->playerMoveOption(*black ,board);
            if (gameLogic.hasMoves(*white)) {
                notOver = 2;
                if(hOrc == 'c' || hOrc == 'C') {
                    gameLogic.turn(*white, *black, ((AiPlayer *) white)->playerLogic(*black));
                } else {
                    gameLogic.turn(*white, *black, ((HumanPlayer *) white)->playerLogic(*black));
                }
            } else {
                notOver--;
                if(notOver) {
                    cout << white->getForm() << ": It's your move.\nNo possible moves. Play passes back to the othe player.\n\n\n";
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
        cout << "Game Over! the winner is: " << black->getForm() :
        cout << "Game Over! the winner is: " << white->getForm();
    }
}