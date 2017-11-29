//
// Or Sharabi 312530496
//Sahar levi 20340514
//

#include <gtest/gtest.h>
#include <src/Board.h>
#include <src/AiPlayer.h>


TEST(LogicEat__TEST, Testing){
    Board tBoard(4);
    Player player1(X);
    player1.addToStack(2,3);
    player1.addToStack(3,2);
    Player player2(O);
    player2.addToStack(2,2);
    player2.addToStack(3,3);
    Disc testChoise;
    testChoise.setDisc(3,4);
    tBoard.fillMatrixBoard(2,player1.getSymbol(),player2.getSymbol());
    GameLogic tLogic(tBoard);

   vector<Player>testEat =  tLogic.eat(player1,player2,testChoise,tBoard);
bool test = true;
    for (int (i) = 0; (i) < testEat[0].getAmount(); ++(i)) {
       if((testEat[0].getDisc(i).getRowLocation() == 2 &&testEat[0].getDisc(i).getColumnLocation() == 2)||
        (testEat[0].getDisc(i).getRowLocation() == 3 &&testEat[0].getDisc(i).getColumnLocation() == 2)||
          (testEat[0].getDisc(i).getRowLocation() == 3 &&testEat[0].getDisc(i).getColumnLocation() == 3)||
       (testEat[0].getDisc(i).getRowLocation() == 3 &&testEat[0].getDisc(i).getColumnLocation() == 4)) {
           test = true;
       }
        else {test =  false;}
    }
    EXPECT_TRUE(test);
    EXPECT_EQ(testEat[1].getAmount(),1);
    EXPECT_EQ(testEat[0].getAmount(),4);
    EXPECT_EQ(testEat[1].getDisc(0).getRowLocation(),2);
    EXPECT_EQ(testEat[1].getDisc(0).getColumnLocation(),2);
}