//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include "Player.h"



Player::Player(Symbol symbol): symbol(symbol) ,StackOfDiscs() {}


Symbol Player::getSymbol() const {
    return symbol;
}

StackOfDiscs Player::getOptionStack() const {
    return optionStack;
}

Disc Player::playerLogic(Player p) {}

void Player::playerMoveOption(const Player opponentPlayer,Board &board) {
    optionStack.emptyStack();
    //Passes the discs that the opposing player has put on the board
    for(int n = 0; n < opponentPlayer.getAmount(); n++) {
        int row = opponentPlayer.getDisc(n).getRowLocation();
        int col = opponentPlayer.getDisc(n).getColumnLocation();
        //Looking for a possible place to put a disc
        for(int i = -1; i < 2; i++) {
            for(int j = -1; j < 2; j++) {
                if(board.getCell(row + i,col + j) == S) {
                    //k and l Pass the matrix in a certain direction to make sure that it is indeed legal to put a disc
                    int k = i;
                    int l = j;
                    while(board.getCell(row - k,col - l) == opponentPlayer.getSymbol()) {
                        k = k + i;
                        l = l + j;
                    }
                    if(board.getCell(row - k,col - l) == symbol) {
                        optionStack.addToStack(row + i,col + j);
                    }
                }
            }
        }
    }
}