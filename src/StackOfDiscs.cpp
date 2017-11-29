//
// Or Sharabi 312530496
//Sahar levi 20340514
//
#include "StackOfDiscs.h"



StackOfDiscs::StackOfDiscs(): stack(vector<Disc>(0)) {}


void StackOfDiscs::addToStack(int i, int j) {
    Disc disc(i,j);
    stack.push_back(disc);
}


void StackOfDiscs::removeFromStack(Disc &disc) {
    for(int i = 0; i <= stack.size(); i++) {
        if (stack[i] == disc) {
            stack.erase(stack.begin() + i);
            break;
        }
    }
}

int StackOfDiscs::getAmount() const {
    return stack.size();
}


Disc StackOfDiscs::getDisc(int x) const {
    return stack.at(x);
}

void StackOfDiscs::isRepeat() {
    for(int i = 0; i < stack.size(); i++) {
        for (int j = i + 1; j < stack.size();) {
            if(stack[i] == stack[j]) {
                stack.erase(stack.begin() + j);
            }
            else {
                j++;
            }
        }
    }
}

bool StackOfDiscs::appear(Disc &disc) {
    for(int i = 0; i < stack.size(); i++) {
        if(disc.getColumnLocation() == stack[i].getColumnLocation() && disc.getRowLocation() == stack[i].getRowLocation()) {
            return true;
        }
    }
    return false;
}

void StackOfDiscs::emptyStack() {
    stack.clear();
}