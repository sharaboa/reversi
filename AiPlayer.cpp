//
// Created by sahar on 26/11/17.
//

#include "AiPlayer.h"


AiPlayer::AiPlayer(const char form,  GameLogic myLogic,Board &gameBoard) : Player(form), myLogic(myLogic),gameBoard(gameBoard) {}

Disc AiPlayer::playerLogic(Player opponentPlayer) {
    Board tempBoardAi = gameBoard.getBoard();
    Board resetAi(tempBoardAi.getSize());
    Board tempBoardHu(tempBoardAi.getSize());
    Board resetBoardHu(tempBoardAi.getSize());
    StackOfDiscs tempStack = optionStack;
    Disc tempChoise;
    Disc finalChoise;
    int maxHumanScore = 0;
    int minHumanScore = 0;

    for(int i = 0; i < tempStack.getAmount(); i++) {
        cout<<"tempBoardAi   "<<endl;
        gameBoard.copyBoard(tempBoardAi);
        tempChoise.setDisc(tempStack.getDisc(i).getRowLocation(),tempStack.getDisc(i).getColumnLocation());
        vector<Player> tempPlayersAfterAiChoose = myLogic.eat(*this,opponentPlayer,tempChoise,tempBoardAi);
        cout<<"tempBoardHu   "<<endl;
        tempBoardAi.copyBoard(tempBoardHu);
        ///////////////////////tempPlayersAfterAiChoose[0] = Ai///////////////////////////
        opponentPlayer.playerMoveOption(tempPlayersAfterAiChoose[0],tempBoardHu);
        for(int j = 0; j < opponentPlayer.getOptionStack().getAmount(); j++) {
            cout<<"resetBoarHu   "<<endl;
            tempBoardHu.copyBoard(resetBoardHu);
            vector<Player> tempPlayersAfterHuChoose = myLogic.eat(tempPlayersAfterAiChoose[1],tempPlayersAfterAiChoose[0],opponentPlayer.getOptionStack().getDisc(j),resetBoardHu);
          cout<<endl<<endl<<endl<<"resetBoardHu after eat";
           resetBoardHu.printBoard();
            if(i==0 && j==0) {
                maxHumanScore = tempPlayersAfterHuChoose[0].getAmount();
                minHumanScore = tempPlayersAfterHuChoose[0].getAmount();
                myChoise.setDisc(tempStack.getDisc(i).getRowLocation(),tempStack.getDisc(i).getColumnLocation());
            }
            if(tempPlayersAfterHuChoose[0].getAmount() < maxHumanScore) {
                maxHumanScore = tempPlayersAfterHuChoose[0].getAmount();
            }

        }
         if(minHumanScore >= maxHumanScore) {
             minHumanScore = maxHumanScore;
             myChoise.setDisc(tempStack.getDisc(i).getRowLocation(),tempStack.getDisc(i).getColumnLocation());
         }
    }


/*
    for (int i = 0 ; i < tempStack.getAmount();i++){
        optionStack.emptyStack();
        myChoise.setDisc(tempStack.getDisc(i).getRowLocation(),tempStack.getDisc(i).getColumnLocation()) ;
        //tempStack2 = the first run for the human player , temp[1]= human player
        cout<<endl<<this<<endl;
        vector<Player> tempStack2 = myLogic.eat(*this,opponentPlayer,myChoise,tempBoard1);
        opponentPlayer.playerMoveOption(tempStack2[1],tempBoard1);
        //tempBoard = gameBoard;
        Board tempBoard = tempBoard1;
        for (int j = 0; j <opponentPlayer.getOptionStack().getAmount() ; ++j) {
            tempBoard.printBoard();
            tempChoise.setDisc(opponentPlayer.getOptionStack().getDisc(j).getRowLocation(),opponentPlayer.getOptionStack().getDisc(j).getColumnLocation());
            //tempStack3 = the second run for the human player temp[0]= human player
            vector<Player> tempstack3 = myLogic.eat(tempStack2[1],tempStack2[0],tempChoise,tempBoard);
            //currentScore = tempstack3[0].getAmount();
            if(j==0 && i==0){
                maxHumanScore = tempstack3[0].getAmount();
            }
            if(tempstack3[0].getAmount() >= maxHumanScore){
                maxHumanScore = tempstack3[0].getAmount();
            }
            minHumanScore = tempstack3[0].getAmount();
        }
        if (maxHumanScore < minHumanScore){
            finalChoise = myChoise;
        }

    }
   */ return myChoise;
}

