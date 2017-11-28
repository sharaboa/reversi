//
// Created by sahar on 28/11/17.
//


#include <gtest/gtest.h>
#include <src/Board.h>
#include <src/AiPlayer.h>
#include <src/HumanPlayer.h>

/*TEST(AiPlayer__TEST, Testing){


    Board board(4);
    GameLogic tGameLogic(board);
    Player *const white = new HumanPlayer(X);
    Player *black;
    black = new AiPlayer(O,tGameLogic,board);

    int midSize = 2;

    board.fillMatrixBoard(midSize,black->getSymbol(),white->getSymbol());

    //board.printBoard();

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
    board.printBoard();

    black->playerMoveOption(*white ,board);

    EXPECT_EQ(black->playerLogic(*white).getRowLocation(),4);
    EXPECT_EQ(black->playerLogic(*white).getColumnLocation(),4);

    delete black;
    delete white;
}*/

TEST(AiPlayer__TEST, Testing2){

    Board board(4);
    GameLogic tGameLogic(board);
    Player *const black = new HumanPlayer(X);
    Player *white;
    white = new AiPlayer(O,tGameLogic,board);

    //initialize board and players
    board.fillMatrixBoard(2,black->getSymbol(),white->getSymbol());
    black->addToStack(2,3);
    black->addToStack(3, 2);
    white->addToStack(2,2);
    black->addToStack(3, 3);
    board.setCell(3,3,black->getSymbol());

    //adding discs to board and players
    black->addToStack(3,4);
    board.setCell(3,4,black->getSymbol());
    black->addToStack(1,1);
    board.setCell(1,1,black->getSymbol());
    white->addToStack(2, 1);
    board.setCell(2,1,white->getSymbol());
    white->addToStack(1,2);
    board.setCell(1,2,white->getSymbol());

    white->playerMoveOption(*black ,board);

    EXPECT_EQ(white->playerLogic(*black).getRowLocation(),4);
    EXPECT_EQ(white->playerLogic(*black).getColumnLocation(),4);

    delete white;
    delete black;
}