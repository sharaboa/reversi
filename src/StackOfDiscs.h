//
// Or Sharabi 312530496
// Created by or on 31/10/17.
//

#ifndef EX2_STACKOFDISCS_H
#define EX2_STACKOFDISCS_H


#include "Disc.h"
#include "Board.h"
#include <vector>
using namespace std;


class StackOfDiscs {
public:
    /**
     * constructor. manages a stack of discs as vector.
     */
    StackOfDiscs();
    /**
     * Adding disc to stack
     * @param i - row
     * @param j - column
     */
    void addToStack(int i, int j);
    /**
     * Removes disc from stack
     * @param disc - need to be removed
     */
    void removeFromStack(Disc &disc);
    /**
     * Returns the number of discs the player places on the board
     * @return
     */
    int getAmount() const;
    /**
     * Returns a disc at the asked location from the stack
     * @param x - index of the disc in stack
     * @return - disc
     */
    Disc getDisc(int x) const;
    /**
     * Removes duplicates from the stack
     */
    void isRepeat();
    /**
     * Compares two discs and returns true if they are the same
     * @param disc - compared disc
     * @return - true if equal
     */
    bool appear(Disc &disc);
    /**
     * clears the stack
     */
    void emptyStack();

private:
    vector<Disc> stack;
};


#endif //EX2_STACKOFDISCS_H