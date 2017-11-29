//
// Or Sharabi 312530496
//Sahar levi 20340514
//

#ifndef EX2_DISC_H
#define EX2_DISC_H


class Disc {
public:
    /**
     * constructor. default
     */
    Disc();
    /**
     * constructor. contains a disc location in the board
     * @param i - row location
     * @param j - column location
     */
    Disc(int i,int j);

    /**
     * return row location of disc
     * @return
     */
    int getRowLocation() const;
    /**
     * return column location of disc
     * @return
     */
    int getColumnLocation() const;
    /**
     * operator overloading
     * compares two discs and return true if epual
     * @param otherDisc - the Equated disc to the stack
     * @return - true if equal
     */

    bool operator ==(const Disc &otherDisc) const;

    void setDisc(int i, int j);

private:
    int row,col;
};


#endif //EX2_DISC_H