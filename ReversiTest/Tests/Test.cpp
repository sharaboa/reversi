//
// Created by or on 28/11/17.
//

#include <gtest/gtest.h>
#include <src/GameLogic.h>

//test at begining of game
TEST(GameLogicTest_TEST, InitializeHasMoves) {
    Board board(8);
    Player black(X);
    Player white(O);
    GameLogic logic(board);


    board.fillMatrixBoard(4, X, O);

    black.addToStack(4, 5);
    black.addToStack(5, 4);
    white.addToStack(4, 4);
    white.addToStack(5, 5);

    black.playerMoveOption(white, board);

    EXPECT_EQ(logic.hasMoves(black), 4);
    EXPECT_EQ(logic.hasMoves(white), 0);
}


//one player can play all moves and the other non
TEST(GameLogicTest_TEST, MiddleGameHasMoves) {
    Board board(8);
    Player black(X);
    Player white(O);
    GameLogic logic(board);

    //initialized
    board.fillMatrixBoard(4,X,O);
    for(int i = 1; i < board.getSize() + 1; i++) {
        for(int j = 1; j < board.getSize() + 1; j++) {
            board.setCell(i,j,S);
        }
    }
    Disc disc;
    white.addToStack(5,5);
    board.setCell(5,5,white.getSymbol());

    for(int i = 4; i < 7; i++) {
        for(int j = 4; j < 7; j++) {
            disc.setDisc(i,j);
            if(!(white.getDisc(0) == disc)) {
                black.addToStack(i,j);
                board.setCell(i,j,black.getSymbol());
            }
        }
    }

   // board.printBoard();

    black.playerMoveOption(white,board);
    white.playerMoveOption(black,board);

    EXPECT_EQ(logic.hasMoves(black),0);
    EXPECT_EQ(logic.hasMoves(white),8);

}
//board full
TEST(GameLogicTest_TEST, EndGameHasMoves) {
    Board board(8);
    Player black(X);
    Player white(O);
    GameLogic logic(board);



    for(int i = 1; i < board.getSize() + 1; i++) {
        for(int j = 1; j < board.getSize() + 1; j++) {
            board.setCell(i,j,X);
            black.addToStack(i,j);
        }
    }

    board.setCell(4,5,O);
    white.addToStack(4, 5);


    black.playerMoveOption(white, board);
    white.playerMoveOption(black,board);

    EXPECT_EQ(logic.hasMoves(black), 0);
    EXPECT_EQ(logic.hasMoves(white), 0);
}

//just one cell left and both can play
TEST(GameLogicTest_TEST, OneLeftGameHasMoves) {
    Board board(8);
    Player black(X);
    Player white(O);
    GameLogic logic(board);

    board.fillMatrixBoard(4,X,X);

    for(int i = 0; i < board.getSize() + 2; i++) {
        for(int j = 0; j < board.getSize() + 2; j++) {
            if(board.getCell(i,j) != B) {
                board.setCell(i, j, X);
                black.addToStack(i,j);
            }
        }
    }
    board.setCell(8,8,S);
    board.setCell(7,7,O);
    board.setCell(8,5,O);
    white.addToStack(7,7);
    white.addToStack(8,5);
    Disc disc1(7,7);
    Disc disc2(8,5);
    Disc disc3(8,8);
    black.removeFromStack(disc1);
    black.removeFromStack(disc2);
    black.removeFromStack(disc3);

    black.playerMoveOption(white, board);
    white.playerMoveOption(black,board);

    EXPECT_EQ(logic.hasMoves(black), 1);
    EXPECT_EQ(logic.hasMoves(white), 1);
}