//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include "AiPlayer.h"


AiPlayer::AiPlayer(Symbol symbol,  GameLogic myLogic,Board &gameBoard) : Player(symbol), myLogic(myLogic),gameBoard(gameBoard) {}

Disc AiPlayer::playerLogic(Player opponentPlayer) {
    Board tempBoardAi(gameBoard.getSize());
    Board resetAi(gameBoard.getSize());
    Board tempBoardHu(gameBoard.getSize());
    Board resetBoardHu(gameBoard.getSize());
    StackOfDiscs tempStack = optionStack;
    Disc tempChoise;
    int maxHumanScore = 0;
    int minHumanScore = 0;

    for(int i = 0; i < tempStack.getAmount(); i++) {
        gameBoard.copyBoard(tempBoardAi);
        tempChoise.setDisc(tempStack.getDisc(i).getRowLocation(),tempStack.getDisc(i).getColumnLocation());
        vector<Player> tempPlayersAfterAiChoose = myLogic.eat(*this,opponentPlayer,tempChoise,tempBoardAi);
        tempBoardAi.copyBoard(tempBoardHu);
        //tempPlayersAfterAiChoose[0] = Ai
        opponentPlayer.playerMoveOption(tempPlayersAfterAiChoose[0],tempBoardHu);
        for(int j = 0; j < opponentPlayer.getOptionStack().getAmount(); j++) {
            tempBoardHu.copyBoard(resetBoardHu);
            vector<Player> tempPlayersAfterHuChoose = myLogic.eat(tempPlayersAfterAiChoose[1],tempPlayersAfterAiChoose[0],opponentPlayer.getOptionStack().getDisc(j),resetBoardHu);
            if(i==0 && j==0) {
                //tempPlayersAfterHuChoose[0] = Human
                maxHumanScore = tempPlayersAfterHuChoose[0].getAmount() - tempPlayersAfterHuChoose[1].getAmount();
                minHumanScore = tempPlayersAfterHuChoose[0].getAmount() - tempPlayersAfterHuChoose[1].getAmount();
                myChoise.setDisc(tempStack.getDisc(i).getRowLocation(),tempStack.getDisc(i).getColumnLocation());
            }
            if(tempPlayersAfterHuChoose[0].getAmount() - tempPlayersAfterHuChoose[1].getAmount() < maxHumanScore) {
                maxHumanScore = tempPlayersAfterHuChoose[0].getAmount() - tempPlayersAfterHuChoose[1].getAmount();
            }
        }
         if(minHumanScore >= maxHumanScore) {
             minHumanScore = maxHumanScore;
             myChoise.setDisc(tempStack.getDisc(i).getRowLocation(),tempStack.getDisc(i).getColumnLocation());
         }
    }
 return myChoise;
}