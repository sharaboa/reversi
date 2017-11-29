//
// Created by sahar on 28/11/17.
//


#include <gtest/gtest.h>
#include <src/Board.h>
#include <src/AiPlayer.h>
#include <src/HumanPlayer.h>

TEST(AiPlayer__TEST, Testing){


    Board board(4);
    GameLogic tGameLogic(board);
    Player *const black = new HumanPlayer(X);
    Player *white;
    white = new AiPlayer(O,tGameLogic,board);

    int midSize = 2;

    board.fillMatrixBoard(midSize,white->getSymbol(),black->getSymbol());
board.printBoard();

    black->addToStack(2,3);
    board.setCell(2,3,black->getSymbol());

    black->addToStack(3, 2);
    board.setCell(3, 2,black->getSymbol());

    black->addToStack(3, 3);
    board.setCell(3, 3,black->getSymbol());


    black->addToStack(3,4);
    board.setCell(3,4,black->getSymbol());


    white->addToStack(2,2);
    board.setCell(2,2,white->getSymbol());

    white->playerMoveOption(*black ,board);
    board.printBoard();
    EXPECT_EQ(white->playerLogic(*black).getRowLocation(),4);
    EXPECT_EQ(white->playerLogic(*black).getColumnLocation(),4);

    delete white;
    delete black;
}