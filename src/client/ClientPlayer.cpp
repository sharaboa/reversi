//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include "ClientPlayer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include "ServerCom.h"

using namespace std;


ClientPlayer::ClientPlayer(Symbol symbol,const char *serverIP, int serverPort):
        HumanPlayer(symbol), serverIP(serverIP), serverPort(serverPort), clientSocket(0), clientNum(0){}

void ClientPlayer::connectToServer() {
// Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
// Convert the ip string to a network address
    struct in_addr address;

    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }

// Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof address, AF_INET);
    if(server == NULL) {
        throw "Host is unreachable";
    }
// Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char*)&address,sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char*)&serverAddress.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
//htonsconverts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);
// Establish a connection with the TCP server
    if(connect(clientSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
}

Disc ClientPlayer::playerLogic(Player opponentPlayer) {
    int rowCord, colCord;
    int choice;
    ServerCom serverCom(clientSocket);
    //choose disc if it's player's turn
    if (clientNum == 1 && symbol == X || clientNum == 2 && symbol == O) {
        if (optionStack.getAmount()) {
            optionStack.isRepeat();
            choice = 1;
            screenView.printEnterMove(optionStack,symbol,choice);
            while (true) {
                char input[50];
                cin.getline(input, 50);
                fromInputToDisc(input);
                rowCord = myChoice.getRowLocation();
                colCord = myChoice.getColumnLocation();
                if (optionStack.appear(myChoice)) {
                    serverCom.writeInt(rowCord);
                    serverCom.writeInt(colCord);
                    return myChoice;
                } else {
                    choice = 0;
                    screenView.printEnterMove(optionStack,symbol,choice);
                }
            }
        } else {
            //there is no move so sending the agreed sign - (0,0)
            int noChoice = 0;
            serverCom.writeInt(noChoice);
            serverCom.writeInt(noChoice);
            return myChoice;
        }
        //updating the choice of the other player
    } else {
        if(optionStack.getAmount()) {
            choice = 2;
            screenView.printEnterMove(optionStack,symbol,choice);
        }
        serverCom.readInt(rowCord);
        serverCom.readInt(colCord);
        myChoice.setDisc(rowCord, colCord);
        return myChoice;
    }
}
int ClientPlayer::getClientNum() {
    return clientNum;
}
int ClientPlayer::getClientSocket() {
    return clientSocket;
}
void ClientPlayer::setClientNum(int myClientNum) {
    clientNum = myClientNum;
}
void ClientPlayer::setClientSocket(int myClientSocket) {
    clientSocket = myClientSocket;
}
void ClientPlayer::notMove() {
    myChoice.setDisc(0,0);
}
void ClientPlayer::gameOver() {
    int over = -2;
    ServerCom serverCom(clientSocket);
    serverCom.writeInt(over);
    serverCom.writeInt(over);
}

void ClientPlayer::readClientNum() {
    //initialize
    int i;
    //read clientNum - 1/2
    ServerCom serverCom(clientSocket);
    serverCom.readInt(i);
    screenView.printClientConnection(clientNum);
    clientNum = i;
    screenView.printClientConnection(clientNum);
}

void ClientPlayer::closeSocket() {
    close(clientSocket);
}