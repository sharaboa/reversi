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
     * @param Symbol the player symbol shows on the board
     */
    explicit Player(Symbol symbol);

    /**
     * @return the player symbol shows on the board
     */
    Symbol getSymbol() const;
    /**
     * @return the stack of disc containing the player option to put discs on the board
     */
    StackOfDiscs getOptionStack() const;
    /**
     * @param p the opponent player
     * @return a disc containing the player choise for his move in the game
     */
    virtual Disc playerLogic(Player p);
/**
 * calculate the player vaild move option
 * @param opponentPlayer the opponent player
 * @param board the game current booard
 */
    void playerMoveOption(const Player opponentPlayer,Board &board);

protected:
    Symbol symbol;
    StackOfDiscs optionStack;

};


#endif //EX2_PLAYER_H