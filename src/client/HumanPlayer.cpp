//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <cstdio>
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(Symbol symbol) : Player(symbol) {}

Disc HumanPlayer::playerLogic(Player opponentPlayer) {
    optionStack.isRepeat();
    int choice = 1;
    screenView.printEnterMove(optionStack,symbol,choice);
    while (true) {
        char input[50];
        cin.getline(input,50);
        fromInputToDisc(input);
        if (optionStack.appear(myChoice)) {
            return myChoice;
        } else{
            choice = 0;
            screenView.printEnterMove(optionStack,symbol,choice);
        }
    }
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
    myChoice.setDisc(row,col);
}