//
// Created by or on 23/12/17.
//

#include "ScreenView.h"

ScreenView::ScreenView() {}

void ScreenView::printMenu(bool choice) const {
    if(choice) {
        cout << "\nWelcome to Reversi\n\n";
        cout << "choose an opponent type:\n1. a human local player\n2. an AI player\n3. a remote player\n";

    } else
        cout << "illegal Choice! choose again\n" << endl;
}

void ScreenView::printBoard(Board &board) const {
    cout << endl << endl;
    cout << "current board:\n\n";
    int size = board.getSize() + 2;
    //prints number by line and column
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1; j++) {
            if (i == 0 && j == 0) {
                cout << " | ";
            } else {
                if (i == 0 && j > 0) {
                    cout << j << " | ";
                } else {
                    if (j == 0 && i > 0) {
                        cout << i << "| ";
                    } else {
                        cout << (char)board.getCell(i,j) << " | ";
                    }
                }
            }
        }
        //prints lines separates lines
        cout << endl << "--";
        for(int k = 0; k < (size - 2) * 4; k++) {
            cout << "-";
        }
        cout << endl;
    }
}

void ScreenView::printEnterMove(StackOfDiscs &optionStack, Symbol currentPlayer,int choice) const {
    switch (choice) {
        //has moves
        case 1: {
            cout << (char) currentPlayer << ": It's your move." << endl << "Your possible moves: ";
            for (int i = 0; i < optionStack.getAmount(); i++) {
                cout << "(" << optionStack.getDisc(i).getRowLocation() << ","
                     << optionStack.getDisc(i).getColumnLocation()
                     << ") ";
            }
            cout << endl << endl << "Please enter your move row,col:";
            break;
        }
            //just in clientPlayer
        case 2: {
            cout << "waiting for other player's move...\n";
            break;
        }
            //illegal move
        case 0: {
            cout << endl << endl << "illegal move! Please enter your move row,col:";
        }
    }
}

void ScreenView::printClientConnection(int connection) const {
    switch (connection) {
        //first connection for both players
        case 0: {
            cout << "connected to server\n";
            break;
        }
            //first player connected
        case 1: {
            cout<<"You are X and the first one to play.\n";
            break;
        }
            //print to o after second player connection
        case 2: {
            cout << "\nYou are O and the second one to play.\n";
            break;
        }
        case -1: {
            "You can not join this game. Please coose another one\n";
            break;
        }
    }
}

void ScreenView::printMove(Board &board, Disc &playerChoice, Symbol player) const {
    printBoard(board);
    cout << endl << (char) player << " played (" << playerChoice.getRowLocation() << ","
         << playerChoice.getColumnLocation() << ")\n\n";
}

void ScreenView::announceWinner(Symbol player1,Symbol player2,int amountPlayer1,int amountPlayer2) const {
    if (amountPlayer1 == amountPlayer2) {
        cout << "Game Over! it's a tie " << endl;
    } else {
        amountPlayer1 > amountPlayer2 ?
        cout << "Game Over! the winner is: " << (char)player1 << endl:
        cout << "Game Over! the winner is: " << (char)player2 << endl;
    }
}

void ScreenView::coutToScreen(string output) const {
    cout<<output<<endl;
}
void ScreenView::remotePlayerMenu() const {
    cout << "Remote player menu:\n";
    cout<< "start<Game_Name>\n";
    cout<<"join<Room_Name>\n";
    cout<<"list_games\n";
    cout << "Choose your command: \n";
}

void ScreenView::printStartCommand(int valid) const {
    if(valid == -1) {
        cout << "Error opening a new Room\n";
    } else {
        cout << "opened a new Room\n";
    }
}

void ScreenView::printServerDisconect() const {
    cout << "server disconnected";
}