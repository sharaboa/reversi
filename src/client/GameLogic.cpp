//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <iostream>
#include "GameLogic.h"

GameLogic::GameLogic(Board &board): board(board) {}

void GameLogic::turn(Player &currentPlayer, Player &opponentPlayer,Disc playerChoice) {
    Disc d(0, 0);
    if (!(playerChoice == d)) {
        vector<Player> tempPlayers = eat(currentPlayer, opponentPlayer, playerChoice, board);
        updateMove(tempPlayers, currentPlayer, opponentPlayer, playerChoice);
        cout << endl << endl;
        cout << "current board:\n\n";
        board.printBoard();
        cout << endl << (char) currentPlayer.getSymbol() << " played (" << playerChoice.getRowLocation() << ","
             << playerChoice.getColumnLocation() << ")";
        cout << " with score: " << currentPlayer.getAmount() - opponentPlayer.getAmount() << "\n\n";
    }
}

vector<Player> GameLogic::eat(Player currentPlayer,Player opponentPlayer,Disc playerChoice,Board &tempBoard) {
    tempBoard.setCell(playerChoice.getRowLocation(),playerChoice.getColumnLocation(),currentPlayer.getSymbol());
    currentPlayer.addToStack(playerChoice.getRowLocation(),playerChoice.getColumnLocation());
    vector<Player> tempPlayers;
    tempPlayers.push_back(currentPlayer);
    tempPlayers.push_back(opponentPlayer);
    int row = playerChoice.getRowLocation();
    int col = playerChoice.getColumnLocation();
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            // m counts how many discs should be replace
            int k = i;
            int l = j;
            int m = 0;
            while(tempBoard.getCell(row + k,col + l) == opponentPlayer.getSymbol()) {
                k = k + i;
                l = l + j;
                m++;
            }
            if(tempBoard.getCell(row + k,col + l) == currentPlayer.getSymbol()) {
                while(m) {
                    k = k - i;
                    l = l - j;
                    tempBoard.setCell(row + k,col + l,currentPlayer.getSymbol());
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

void GameLogic::updateMove(const vector<Player>& tempPlayers, Player &currentPlayer, Player &opponentPlayer,Disc &playerChoice) {
    currentPlayer = tempPlayers[0];
    opponentPlayer = tempPlayers[1];
    board.setCell(playerChoice.getRowLocation(),playerChoice.getColumnLocation(),currentPlayer.getSymbol());
    for(int i = 0; i < 2; i++) {
        for(int j = 0;j < tempPlayers[i].getAmount(); j++) {
            board.setCell(tempPlayers[i].getDisc(j).getRowLocation(),tempPlayers[i].getDisc(j).getColumnLocation(),tempPlayers[i].getSymbol());
        }
    }
}

int GameLogic::hasMoves(Player &currentPlayer) const {
    return currentPlayer.getOptionStack().getAmount();
}