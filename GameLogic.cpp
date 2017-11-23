//
// Or Sharabi 312530496
// Created by or on 01/11/17.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "GameLogic.h"

GameLogic::GameLogic(Board &board): board(board) {}

void GameLogic::turn(Player &currentPlayer, Player &opponentPlayer) {
    stackOfOptions.isRepeat();
    cout << currentPlayer.getForm() << ": It's your move." << endl << "Your possible moves: ";
    for (int i = 0; i < stackOfOptions.getAmount(); i++) {
        cout << "(" << stackOfOptions.getDisc(i).getRowLocation() << "," << stackOfOptions.getDisc(i).getColumnLocation() << ") ";
    }
    cout << endl << endl << "Please enter your move row,col:";
    while (true) {
        char input[50];
        cin.getline(input,50);
        playerChoise = fromStringToDisc(input);
        if (stackOfOptions.appear(playerChoise)) {
            vector<Player> tempPlayers = eat(currentPlayer,opponentPlayer);
            updateMove(tempPlayers, currentPlayer, opponentPlayer);
            break;
        } else {
            cout << endl << endl << "illegal move! Please enter your move row,col:";
        }
    }
    cout << endl << endl;
    cout << "current board:\n\n";
    board.printBoard();
}

Disc GameLogic::fromStringToDisc(char input[50]) {
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
}

void GameLogic::options(const char &winning,const Player &loosing) {
    stackOfOptions.emptyStack();
    //Passes the discs that the opposing player has put on the board
    for(int n = 0; n < loosing.getAmount(); n++) {
        int row = loosing.getDisc(n).getRowLocation();
        int col = loosing.getDisc(n).getColumnLocation();
        //Looking for a possible place to put a disc
        for(int i = -1; i < 2; i++) {
            for(int j = -1; j < 2; j++) {
                if(board.getCell(row + i,col + j) == ' ') {
                    //k and l Pass the matrix in a certain direction to make sure that it is indeed legal to put a disc
                    int k = i;
                    int l = j;
                    while(board.getCell(row - k,col - l) == loosing.getForm()) {
                        k = k + i;
                        l = l + j;
                    }
                    if(board.getCell(row - k,col - l) == winning) {
                        stackOfOptions.addToStack(row + i,col + j);
                    }
                }
            }
        }
    }
}

vector<Player> GameLogic::eat(Player winning,Player loosing) {
    vector<Player> tempPlayers;
    tempPlayers.push_back(winning);
    tempPlayers.push_back(loosing);
    int row = playerChoise.getRowLocation();
    int col = playerChoise.getColumnLocation();
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            // m counts how many discs should be replace
            int k = i;
            int l = j;
            int m = 0;
            while(board.getCell(row + k,col + l) == loosing.getForm()) {
                k = k + i;
                l = l + j;
                m++;
            }
            if(board.getCell(row + k,col + l) == winning.getForm()) {
                while(m) {
                    k = k - i;
                    l = l - j;
                    //board.setCell(row + k,col + l,winning.getForm());
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

void GameLogic::updateMove(const vector<Player>& tempPlayers, Player &currentPlayer, Player &opponentPlayer) {
    currentPlayer = tempPlayers[0];
    currentPlayer.addToStack(playerChoise.getRowLocation(), playerChoise.getColumnLocation());
    opponentPlayer = tempPlayers[1];
    board.setCell(playerChoise.getRowLocation(),playerChoise.getColumnLocation(),currentPlayer.getForm());
    for(int i = 0; i < 2; i++) {
       for(int j = 0;j < tempPlayers[i].getAmount(); j++) {
           board.setCell(tempPlayers[i].getDisc(j).getRowLocation(),tempPlayers[i].getDisc(j).getColumnLocation(),tempPlayers[i].getForm());
       }
    }
}

void GameLogic::noTurn(const char &winning,const char &loosing) {
    cout << winning << " played (" << playerChoise.getRowLocation() << "," << playerChoise.getColumnLocation() << ")" << endl << endl;
    cout << loosing << ": It's your move.\nNo possible moves. Play passes back to the othe player.\n\n\n";

}

int GameLogic::hasMoves() const {
    return stackOfOptions.getAmount();
}