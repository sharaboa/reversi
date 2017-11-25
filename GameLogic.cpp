//
// Or Sharabi 312530496
// Created by or on 01/11/17.
//

#include <iostream>
#include "GameLogic.h"

GameLogic::GameLogic(Board &board): board(board) {}

void GameLogic::turn(Player &currentPlayer, Player &opponentPlayer,Disc playerChoise) {
    vector<Player> tempPlayers = eat(currentPlayer,opponentPlayer,playerChoise);
    updateMove(tempPlayers, currentPlayer, opponentPlayer,playerChoise);
    cout << endl << endl;
    cout << "current board:\n\n";
    board.printBoard();
    cout <<endl<< currentPlayer.getForm() << " played (" << playerChoise.getRowLocation() << "," << playerChoise.getColumnLocation() << ")" << endl << endl;

}

/*Disc GameLogic::fromStringToDisc(char input[50]) {
    int row, col;
    char* index;
    index = strtok(input,",");
    string modified[2];
    int i = 0;
    while(index!= NULL) {
        modified[i].append(index);
        index = strtok(NULL,",");
        i++;
    }
    sscanf(modified[0].c_str(), "%d", &row);
    sscanf(modified[1].c_str(),"%d",&col);
    Disc disc(row,col);
    return disc;
}*/
/*
void GameLogic::options(const char &currentPlayer,const Player &opponentPlayer) {
    stackOfOptions.emptyStack();
    //Passes the discs that the opposing player has put on the board
    for(int n = 0; n < opponentPlayer.getAmount(); n++) {
        int row = opponentPlayer.getDisc(n).getRowLocation();
        int col = opponentPlayer.getDisc(n).getColumnLocation();
        //Looking for a possible place to put a disc
        for(int i = -1; i < 2; i++) {
            for(int j = -1; j < 2; j++) {
                if(board.getCell(row + i,col + j) == ' ') {
                    //k and l Pass the matrix in a certain direction to make sure that it is indeed legal to put a disc
                    int k = i;
                    int l = j;
                    while(board.getCell(row - k,col - l) == opponentPlayer.getForm()) {
                        k = k + i;
                        l = l + j;
                    }
                    if(board.getCell(row - k,col - l) == currentPlayer) {
                        stackOfOptions.addToStack(row + i,col + j);
                    }
                }
            }
        }
    }
}*/

vector<Player> GameLogic::eat(Player currentPlayer,Player opponentPlayer,Disc playerChoise) {
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
            while(board.getCell(row + k,col + l) == opponentPlayer.getForm()) {
                k = k + i;
                l = l + j;
                m++;
            }
            if(board.getCell(row + k,col + l) == currentPlayer.getForm()) {
                while(m) {
                    k = k - i;
                    l = l - j;
                    //board.setCell(row + k,col + l,currentPlayer.getForm());
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
    currentPlayer.addToStack(playerChoise.getRowLocation(),playerChoise.getColumnLocation());
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