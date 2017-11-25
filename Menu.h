//
// Created by or on 23/11/17.
//

#ifndef REVERSI_MENU_H
#define REVERSI_MENU_H

#include <iostream>
#include <limits>

using namespace std;


class Menu {
public:
    Menu(int size,char black,char white);
    char opponentType();
private:
    const char black;
    const char white;
    const int size;
};


#endif //REVERSI_MENU_H
