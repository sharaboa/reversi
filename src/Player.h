//
// Or Sharabi 312530496
//Sahar levi 203405147
//
#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H


#include "StackOfDiscs.h"
#include "Disc.h"
#include <iostream>
#include <vector>


using namespace std;

class Player: public StackOfDiscs {
public:
    /**
     * constructor.
     * Get the form of the player and initialize a stack of discs that the player puts on the board
     * @param form
     */
    explicit Player(Symbol symbol);

    /**
     * Returns the view on the board of the player
     * @return
     */
    Symbol getSymbol() const;
    StackOfDiscs getOptionStack() const;
    virtual Disc playerLogic(Player p);

    void playerMoveOption(const Player opponentPlayer,Board &board);

protected:
    Symbol symbol;
    StackOfDiscs optionStack;

};


#endif //EX2_PLAYER_H