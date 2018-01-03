//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <iostream>
#include "ReversiGame.h"
#include "ClientPlayer.h"
#include <typeinfo>
#include <fstream>
#include <limits>
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
    inFile.open("setting.txt");
    inFile >> data;
    inFile >> port;
    inFile.close();
    const char *serverIP = data.c_str();

    ClientPlayer player1(b, serverIP, port);
    ClientPlayer player2(w, serverIP, port);
    int repeat = 1;
    CommandMannager myMannager;
    ScreenView myView;
    string command,input,arg;
    while(repeat) {
        player1.connectToServer();
        player2.setClientSocket(player1.getClientSocket());
        player2.setClientNum(player1.getClientNum());


        bool validInput = false;
        while(!validInput) {
            myView.remotePlayerMenu();
            cin >> command;
            if (myMannager.validCommand(command)) {
                input.append(command);
                if (command.compare("list_games") != 0) {
                    cin >> arg;
                    input.append(" ");
                    input.append(arg);
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                validInput = myMannager.validCommand(command);
            } else {
                screenView.coutToScreen("invalid input!");
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        bool validArg = true;
        myMannager.executeCommand(input,validArg, player1.getClientSocket());

        if (((command.compare("join") == 0 ||command.compare("start") == 0))&&validArg) {
            initialize(&player1, &player2, board);
            player1.readClientNum();
            player2.setClientNum(player1.getClientNum());
            play(&player1, &player2);
            repeat = 0;
            player1.closeSocket();
        }
        command.clear();
        input.clear();
    }
}

void ReversiGame::play(Player *current,Player *opponent) {
    //notOver zeroed when both players have no moves
    int notOver = 2;
    screenView.printBoard(board);
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