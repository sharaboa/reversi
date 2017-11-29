//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <gtest/gtest.h>
#include <src/Board.h>
#include <src/AiPlayer.h>
#include <src/HumanPlayer.h>
//check that the ai logic works and calculate the correct move
TEST(AiPlayer__TEST, Testing){


    Board board(4);
    GameLogic tGameLogic(board);
    Player *const black = new HumanPlayer(X);
    Player *white;
    white = new AiPlayer(O,tGameLogic,board);

    int midSize = 2;

    board.fillMatrixBoard(midSize,white->getSymbol(),black->getSymbol());


    black->addToStack(1,1);
    board.setCell(1,1,black->getSymbol());

    black->addToStack(2, 3);
    board.setCell(2, 3,black->getSymbol());

    black->addToStack(3, 2);
    board.setCell(3, 2,black->getSymbol());


    black->addToStack(3,3);
    board.setCell(3,3,black->getSymbol());

    black->addToStack(3,4);
    board.setCell(3,4,black->getSymbol());

    white->addToStack(2,2);
    board.setCell(2,2,white->getSymbol());

    white->addToStack(2,1);
    board.setCell(2,1,white->getSymbol());

    white->addToStack(1,2);
    board.setCell(1,2,white->getSymbol());

    white->playerMoveOption(*black ,board);


    EXPECT_EQ(white->playerLogic(*black).getRowLocation(),4);
    EXPECT_EQ(white->playerLogic(*black).getColumnLocation(),4);

    delete white;
    delete black;
}
