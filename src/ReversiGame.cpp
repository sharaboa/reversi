//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <iostream>
#include <sys/socket.h>
#include <fstream>
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
            initialize(black,white,board);
            play(black,white);
            break;
        }
        case '2': {

            black =new HumanPlayer(b);
            white = new  AiPlayer(w,gameLogic,board);
            initialize(black,white,board);
            play(black,white);
            break;
        }
        case '3':{

            string IP;
            string data;
            int port;
            ifstream inFile;
            inFile.open("/home/sahar/CLionProjects/reversi/reversi/src/setting.txt");
            inFile >> data;
            cout<<"IP: "<<data<<endl;
            inFile >> port;
            cout<<"port: "<<port<<endl;
            inFile.close();
            const char * serverIP = data.c_str();

            ClientPlayer player1(b,serverIP,port);
            player1.connectToServer();
            ClientPlayer player2(w,serverIP,port);
            player2.setClientSocket(player1.getClientSocket());
            player2.setClientNum(player1.getClientNum());
            cout<<player1.getClientNum()<<"aaaa";
            black = &player1;
            white=&player2;
            cout<<player1.getClientSocket()<<endl;
            cout<<player2.getClientSocket()<<endl;

            initialize(black,white,board);
            playClient(black, white);

            break;
        }
    }
    delete black;
    delete white;
}
void ReversiGame::initialize (Player *black, Player *white, Board &board){
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

void ReversiGame::playClient(Player *currentPlayer,Player *opponentPlayer) {
    //notOver zeroed when both players have no moves
    int notOver = 2;
    cout << "current board:\n";
    board.printBoard();
    while(notOver && currentPlayer->getAmount() + opponentPlayer->getAmount() != size*size) {
        currentPlayer->playerMoveOption(*opponentPlayer ,board);
        if (gameLogic.hasMoves(*currentPlayer)) {
            notOver = 2;
            gameLogic.turn(*currentPlayer, *opponentPlayer, currentPlayer->playerLogic(*opponentPlayer));
        } else {
            notOver--;
            if(notOver) {
                cout << (char)currentPlayer->getSymbol() << ": It's your move.\nNo possible moves. Play passes back to the othe player.\n\n\n";
                ((ClientPlayer*)currentPlayer)->notMove();

            }
        }
        if(notOver && currentPlayer->getAmount() + opponentPlayer->getAmount() != size*size) {
            opponentPlayer->playerMoveOption(*currentPlayer ,board);
            if (gameLogic.hasMoves(*opponentPlayer)) {
                notOver = 2;
                gameLogic.turn(*opponentPlayer, *currentPlayer,opponentPlayer->playerLogic(*currentPlayer));
            } else {
                notOver--;
                if(notOver) {
                    cout << (char)opponentPlayer->getSymbol() << ": It's your move.\nNo possible moves. Play passes back to the othe player.\n\n\n";
                    ((ClientPlayer*)opponentPlayer)->notMove();
                }
            }
        }
    }

    ((ClientPlayer*)currentPlayer)->gameOver();
    announceWinner(currentPlayer,opponentPlayer);
}