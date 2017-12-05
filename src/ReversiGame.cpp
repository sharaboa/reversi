//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <iostream>
#include <sys/socket.h>
#include "ReversiGame.h"
#include "ClientPlayer.h"

ReversiGame::ReversiGame(int size): board(size),gameLogic(board),size(size) {}


void ReversiGame::manage(Symbol b, Symbol w, char x) {
    Player *black;
    Player *white;
    switch (x) {
        case '1':  {
            black =new HumanPlayer(b);
            white =new HumanPlayer(w);
            initiallize(black,white,board);
            play(black,white);
            break;
        }
        case '2': {

            black =new HumanPlayer(b);
            white = new  AiPlayer(w,gameLogic,board);
            initiallize(black,white,board);
            play(black,white);
            break;
        }
        case '3':{
            ClientPlayer player1(b,"0.0.0.0",6887);
            player1.connectToServer();
            ClientPlayer player2(w,"0.0.0.0",6887);
            player2.setClientSocket(player1.getClientSocket());
            player2.setClientNum(player1.getClientNum());
            cout<<player1.getClientNum();
            black = &player1;
            white=&player2;
            break;
        }
    }
    delete black;
    delete white;
}
void ReversiGame::initiallize (Player *black, Player *white, Board &board){
    int midSize = size / 2;
    board.fillMatrixBoard(midSize,black->getSymbol(),white->getSymbol());
    white->addToStack(midSize + 1,midSize + 1);
    white->addToStack(midSize, midSize);
    black->addToStack(midSize, midSize + 1);
    black->addToStack(midSize + 1,midSize);
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