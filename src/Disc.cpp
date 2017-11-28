//
// Or Sharabi 312530496
// Created by or on 31/10/17.

#include "Disc.h"

Disc::Disc(int i, int j) : row(i),col(j) {}

Disc::Disc() {}

int Disc::getRowLocation() const {
    return row;
}

int Disc::getColumnLocation() const {
    return col;
}

bool Disc::operator==(const Disc &otherDisc) const {
    return otherDisc.getColumnLocation() == col && otherDisc.getRowLocation() == row;
}

void Disc::setDisc(int i, int j) {
    row = i;
    col = j;

}
