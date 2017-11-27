//Or Sharabi 312530496
#include <iostream>
#include "ReversiGame.h"
#include "Menu.h"

using namespace std;

int main() {
   /* Board board(6);
    board.fillMatrixBoard(3,'X','O');
    cout<<"origin board   "<<endl;
    board.setCell(1,1,'@');
    board.printBoard();
    cout<<board.getCell(1,1)<<endl;
    Board board1(6);
    board.copyBoard(board1);
    cout<<"copy board   "<<endl;
    board1.printBoard();*/
    Menu reversi(4,'X','O');
   reversi.opponentType();
    //char winner = reversi.play();
  /*  if(winner == ' ') {
        cout << "Game Over! it's a tie " << endl;
    } else {
        cout << "Game Over! the winner is: " << winner << endl;
    }*/
}