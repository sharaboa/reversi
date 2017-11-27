//
// Or Sharabi 312530496
// Created by or on 01/11/17.
//

#include <iostream>
#include "GameLogic.h"

GameLogic::GameLogic(Board &board): board(board) {}

void GameLogic::turn(Player &currentPlayer, Player &opponentPlayer,Disc playerChoise) {
    vector<Player> tempPlayers = eat(currentPlayer,opponentPlayer,playerChoise,board);
    updateMove(tempPlayers, currentPlayer, opponentPlayer,playerChoise);
    cout << endl << endl;
    cout << "current board:\n\n";
    board.printBoard();
    cout <<endl<< currentPlayer.getForm() << " played (" << playerChoise.getRowLocation() << "," << playerChoise.getColumnLocation() << ")" << endl << endl;

}

vector<Player> GameLogic::eat(Player currentPlayer,Player opponentPlayer,Disc playerChoise,Board &tempBoard) {
    tempBoard.setCell(playerChoise.getRowLocation(),playerChoise.getColumnLocation(),currentPlayer.getForm());
    currentPlayer.addToStack(playerChoise.getRowLocation(),playerChoise.getColumnLocation());
    vector<Player> tempPlayers;
    tempPlayers.push_back(currentPlayer);
    tempPlayers.push_back(opponentPlayer);

    int row = playerChoise.getRowLocation();
    int col = playerChoise.getColumnLocation();
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            // m counts how many discs should be replace
            int k = i;
            int l = j;
            int m = 0;
            while(tempBoard.getCell(row + k,col + l) == opponentPlayer.getForm()) {
                k = k + i;
                l = l + j;
                m++;
            }
            if(tempBoard.getCell(row + k,col + l) == currentPlayer.getForm()) {
                while(m) {
                    k = k - i;
                    l = l - j;
                    tempBoard.setCell(row + k,col + l,currentPlayer.getForm());
                    Disc loose(row + k, col + l);
                    tempPlayers[0].addToStack(row+k,col+l);
                    tempPlayers[1].removeFromStack(loose);
                    m--;
                }
            }
        }
    }
    return tempPlayers;
}

void GameLogic::updateMove(const vector<Player>& tempPlayers, Player &currentPlayer, Player &opponentPlayer,Disc &playerChoise) {
    currentPlayer = tempPlayers[0];
    opponentPlayer = tempPlayers[1];
    board.setCell(playerChoise.getRowLocation(),playerChoise.getColumnLocation(),currentPlayer.getForm());
    for(int i = 0; i < 2; i++) {
       for(int j = 0;j < tempPlayers[i].getAmount(); j++) {
           board.setCell(tempPlayers[i].getDisc(j).getRowLocation(),tempPlayers[i].getDisc(j).getColumnLocation(),tempPlayers[i].getForm());
       }
    }
}

int GameLogic::hasMoves(Player &currentPlayer) const {
    return currentPlayer.getOptionStack().getAmount();
}