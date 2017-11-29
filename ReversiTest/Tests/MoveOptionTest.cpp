//
// Created by or on 29/11/17.
//

#include <gtest/gtest.h>
#include <src/GameLogic.h>

//
TEST(MoveOption_TEST, PlayerMoveOption) {
    Board board(8);
    Player black(X);
    Player white(O);
    GameLogic logic(board);


    board.fillMatrixBoard(4,X,O);
    black.addToStack(4, 5);
    black.addToStack(5, 4);
    white.addToStack(4, 4);

    board.setCell(5,5,X);
    black.addToStack(5, 5);




    black.playerMoveOption(white, board);
    white.playerMoveOption(black,board);

    //EXPECT_EQ(logic.hasMoves(black), 0);
    //EXPECT_EQ(logic.hasMoves(white), 0);
}