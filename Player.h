//
// Or Sharabi 312530496
// Created by or on 31/10/17.
//

#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


#include "StackOfDiscs.h"
#include "Disc.h"
#include <vector>

using namespace std;

class Player: public StackOfDiscs {
public:
    /**
     * constructor.
     * Get the form of the player and initialize a stack of discs that the player puts on the board
     * @param form
     */
    explicit Player(const char form);

    /**
     * Returns the view on the board of the player
     * @return
     */
    char getForm() const;

private:
    char form;
};


#endif //EX2_PLAYER_H