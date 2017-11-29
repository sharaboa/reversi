//
// Or Sharabi 312530496
//Sahar levi 20340514
//

#include <gtest/gtest.h>
#include <src/GameLogic.h>


//checks if the option presented is correct
TEST(MoveOption_TEST, PlayerMoveOption) {
    //initialize parameters
    Board board(8);
    Player black(X);
    Player white(O);
    GameLogic logic(board);
    StackOfDiscs optionOfBlack;
    StackOfDiscs optionOfWhite;


    board.fillMatrixBoard(4,X,O);
    black.addToStack(4, 5);
    black.addToStack(5, 4);
    white.addToStack(4, 4);
    white.addToStack(5,5);

    board.setCell(3,4,X);
    black.addToStack(3,4);
    board.setCell(3,5,X);
    black.addToStack(3,5);

    //option we expect to get
    optionOfBlack.addToStack(5,6);
    optionOfBlack.addToStack(6,5);
    optionOfBlack.addToStack(5,3);
    optionOfBlack.addToStack(4,3);

    optionOfWhite.addToStack(2,4);
    optionOfWhite.addToStack(2,5);
    optionOfWhite.addToStack(2,6);
    optionOfWhite.addToStack(4,6);
    optionOfWhite.addToStack(5,3);
    optionOfWhite.addToStack(6,4);

    black.playerMoveOption(white, board);
    white.playerMoveOption(black,board);

    //comparing two stacks by removing equal disc
    for(int i = 0; i < black.getOptionStack().getAmount(); i++) {
        for(int j = 0; j < optionOfBlack.getAmount();) {
            Disc disc = optionOfBlack.getDisc(j);
            if(black.getOptionStack().appear(disc)) {
                optionOfBlack.removeFromStack(disc);
            } else {
                j++;
            }
        }
    }

    for(int i = 0; i < white.getOptionStack().getAmount(); i++) {
        for(int j = 0; j < optionOfWhite.getAmount();) {
            Disc disc = optionOfWhite.getDisc(j);
            if(white.getOptionStack().appear(disc)) {
                optionOfWhite.removeFromStack(disc);
            } else {
                j++;
            }
        }
    }

    EXPECT_EQ(optionOfBlack.getAmount(), 0);
    EXPECT_EQ(optionOfWhite.getAmount(), 0);
}