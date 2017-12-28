//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <iostream>
#include "ReversiGame.h"
#include "ClientPlayer.h"
#include <typeinfo>
#include <fstream>
#include "CommandMannager.h"

ReversiGame::ReversiGame(int size): board(size),gameLogic(board),size(size) {}


void ReversiGame::initialize (Player *black, Player *white, Board &board){
    int midSize = size / 2;
    board.fillMatrixBoard(midSize,black->getSymbol(),white->getSymbol());
    white->addToStack(midSize + 1,midSize + 1);
    white->addToStack(midSize, midSize);
    black->addToStack(midSize, midSize + 1);
    black->addToStack(midSize + 1,midSize);
}

void ReversiGame::manageHuman(Symbol b, Symbol w) {
    HumanPlayer black(b);
    HumanPlayer white(w);
    initialize(&black,&white,board);
    play(&black,&white);
}
void ReversiGame::manageAi(Symbol b, Symbol w) {
    Player *black;
    Player *white;
    black =new HumanPlayer(b);
    white = new  AiPlayer(w,gameLogic,board);
    initialize(black,white,board);
    play(black,white);
    delete black;
    delete white;
}
void ReversiGame::manageRemoteGame(Symbol b, Symbol w) {
    string data;
    int port;
    ifstream inFile;
    inFile.open("/home/sahar/CLionProjects/reversi/src/src/client/setting.txt");
    inFile >> data;
    inFile >> port;
    inFile.close();
    const char *serverIP = data.c_str();

    ClientPlayer player1(b, serverIP, port);
    player1.connectToServer();
    ClientPlayer player2(w, serverIP, port);
    player2.setClientSocket(player1.getClientSocket());
    player2.setClientNum(player1.getClientNum());
    initialize(&player1, &player2, board);
    int repeat = 1;
    CommandMannager myMannager;
    ScreenView myView;
    string command,arg,input;
    while(repeat) {
        bool validInput = false;
        while(!validInput) {
            myView.remotePlayerMenu();
            cin >> input;
            int s = input.find('<');
            //int y = input.find('>');
            command = input.substr(0, s);
            //arg = input.substr(s + 1, y);
            //arg.erase(arg.end() - 1, arg.end());
            validInput = myMannager.validCommand(command);
        }
        myMannager.executeCommand(input, player1.getClientSocket());
        if (command.compare("join")) {
            play(&player1, &player2);
            myMannager.executeCommand("close",player1.getClientSocket());
            repeat = 0;
        }
    }
}

void ReversiGame::play(Player *current,Player *opponent) {
    //notOver zeroed when both players have no moves
    int notOver = 2;
    screenView.printBoard(board);
    //board.printBoard();
    while(notOver && current->getAmount() + opponent->getAmount() != size*size) {
        current->playerMoveOption(*opponent ,board);
        if (gameLogic.hasMoves(*current)) {
            notOver = 2;
            gameLogic.turn(*current, *opponent, current->playerLogic(*opponent));
        } else {
            notOver--;
            if(notOver) {
                cout << (char)current->getSymbol() << ": It's your move.\nNo possible moves. Play passes back to the othe player.\n\n\n";
                if(typeid(*current) == typeid(ClientPlayer)) {
                    ((ClientPlayer*)current)->notMove();
                    gameLogic.turn(*current, *opponent, current->playerLogic(*opponent));
                }
            }
        }
        swap(current,opponent);
    }
    if(typeid(*current) == typeid(ClientPlayer)) {
        ((ClientPlayer*)current)->gameOver();
    }
    screenView.announceWinner(current->getSymbol(),opponent->getSymbol(),current->getAmount(),opponent->getAmount());
}