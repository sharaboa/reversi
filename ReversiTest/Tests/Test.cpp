//
// Created by or on 28/11/17.
//

#include <gtest/gtest.h>
#include <src/Board.h>

TEST(Board__TEST, Testing) {
    Board* b;
    b = new Board(5);
    delete b;
}