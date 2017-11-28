//
// Created by sahar on 28/11/17.
//


#include <gtest/gtest.h>
#include <src/Board.h>
#include <src/AiPlayer.h>
#include <src/HumanPlayer.h>

TEST(AiPlayer__TEST, Testing){
    Board tBoard(6);
    tBoard.fillMatrixBoard(3,O,X);
    GameLogic tGameLogic(tBoard);
    Player *const white = new HumanPlayer(O);
    Player *black;
    black = new AiPlayer(X,tGameLogic,tBoard);


    Board board(6);
    int midSize = 4;



    board.fillMatrixBoard(midSize,black->getSymbol(),white->getSymbol());

    white->addToStack(2,3);
    board.setCell(2,3,white->getSymbol());

    white->addToStack(3, 2);
    board.setCell(3, 2,white->getSymbol());

    white->addToStack(3, 3);
    board.setCell(3, 3,white->getSymbol());


    white->addToStack(3,4);
    board.setCell(3,4,white->getSymbol());


    black->addToStack(2,2);
    board.setCell(2,2,black->getSymbol());


    black->playerMoveOption(*white ,board);

    EXPECT_EQ(black->playerLogic(*white).getRowLocation(),4);
    EXPECT_EQ(black->playerLogic(*white).getRowLocation(),4);
    delete black;
    delete white;
}