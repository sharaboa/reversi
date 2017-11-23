//
// Created by sahar on 23/11/17.
//

#include <cstdio>
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(const char form) : Player(form) {}

Disc HumanPlayer::playerLogic() {
    optionStack.isRepeat();
    cout << form << ": It's your move." << endl << "Your possible moves: ";
    for (int i = 0; i < optionStack.getAmount(); i++) {
        cout << "(" << optionStack.getDisc(i).getRowLocation() << "," << optionStack.getDisc(i).getColumnLocation() << ") ";
    }
    cout << endl << endl << "Please enter your move row,col:";
    while (true) {
        char input[50];
        cin.getline(input,50);
        fromInputToDisc(input);
        if (optionStack.appear(myChoise)) {
            return myChoise;
            //cout << endl << endl << "illegal move! Please enter your move row,col:";
        }
        else{
            cout << endl << endl << "illegal move! Please enter your move row,col:";
        }
    }


  /*  cout << endl << endl;
    cout << "current board:\n\n";
    board.printBoard();*/

}

void HumanPlayer::fromInputToDisc(char input[50]) {
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
    myChoise.setDisc(row,col);
}