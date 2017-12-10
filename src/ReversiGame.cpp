//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <iostream>
#include "ReversiGame.h"
#include "ClientPlayer.h"
#include <typeinfo>


ReversiGame::ReversiGame(int size): board(size),gameLogic(board),size(size) {}


void ReversiGame::initialize (Player *black, Player *white, Board &board){
    int midSize = size / 2;
    board.fillMatrixBoard(midSize,black->getSymbol(),white->getSymbol());
    white->addToStack(midSize + 1,midSize + 1);
    white->addToStack(midSize, midSize);
    black->addToStack(midSize, midSize + 1);
    black->addToStack(midSize + 1,midSize);
}

void ReversiGame::manageHuman(Symbol b, Symbol w) {
    HumanPlayer black(b);
    HumanPlayer white(w);
    initialize(&black,&white,board);
    play(&black,&white);
}
void ReversiGame::manageAi(Symbol b, Symbol w) {
    Player *black;
    Player *white;
    black =new HumanPlayer(b);
    white = new  AiPlayer(w,gameLogic,board);
    initialize(black,white,board);
    play(black,white);
    delete black;
    delete white;
}
void ReversiGame::manageRemoteGame(Symbol b, Symbol w){


    ClientPlayer player1(b,"127.0.0.1",8888);
    player1.connectToServer();
    ClientPlayer player2(w,"127.0.0.1",8888);
    player2.setClientSocket(player1.getClientSocket());
    player2.setClientNum(player1.getClientNum());
    initialize(&player1,&player2,board);
    play(&player1, &player2);
}

void ReversiGame::play(Player *current,Player *opponent) {
    //notOver zeroed when both players have no moves
    int notOver = 2;
    cout << "current board:\n";
    board.printBoard();
    while(notOver && current->getAmount() + opponent->getAmount() != size*size) {
        current->playerMoveOption(*opponent ,board);
        if (gameLogic.hasMoves(*current)) {
            notOver = 2;
            gameLogic.turn(*current, *opponent, current->playerLogic(*opponent));
        } else {
            notOver--;
            if(notOver) {
                cout << (char)current->getSymbol() << ": It's your move.\nNo possible moves. Play passes back to the othe player.\n\n\n";
                if(typeid(*current) == typeid(ClientPlayer)) {
                    //if (current->getPlayerType() == 2){
                    ((ClientPlayer*)current)->notMove();
                    gameLogic.turn(*current, *opponent, current->playerLogic(*opponent));
                }
            }
        }
        swap(current,opponent);
    }
    if(typeid(*current) == typeid(ClientPlayer)) {
        //if (current->getPlayerType() == 2){
        ((ClientPlayer*)current)->gameOver();
    }
    announceWinner(current,opponent);
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