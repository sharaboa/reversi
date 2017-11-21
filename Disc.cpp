//
// Or Sharabi 312530496
// Created by or on 31/10/17.
//

#include "Disc.h"

Disc::Disc(int i, int j) : location() {
    location[0] = i;
    location[1] = j;
}

Disc::Disc() {}

int Disc::getRowLocation() const {
    return location[0];
}

int Disc::getColumnLocation() const {
    return location[1];
}


bool Disc::isSimilar(Disc otherDisc) {
    return otherDisc.getColumnLocation() == location[1] && otherDisc.getRowLocation() == location[0];
}
