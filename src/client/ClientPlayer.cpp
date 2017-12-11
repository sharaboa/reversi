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
using namespace std;
ClientPlayer::ClientPlayer(Symbol symbol,const char *serverIP, int serverPort): HumanPlayer(symbol),serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
    clientNum = 0;
}
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

    //initialize
    int i;
    //read clientNum - 1/2
    int n = read(clientSocket, &i, sizeof(i));
    if (n == -1) {
        throw "Error writing arg1to socket";
    }
    clientNum = i;
    if(clientNum == 1) {
        cout << "You are X and the first one to play.\n";
        cout<<"waiting for other player to join...\n"<<endl;
        //waite for second player to connect
        int n = read(clientSocket, &i, sizeof(i));
        if (n == -1) {
            throw "Error writing arg1to socket";
        }
    }
    if(clientNum == 2){
        cout << "You are O and the second one to play.\n";
    }
}

Disc ClientPlayer::playerLogic(Player opponentPlayer) {
    int rowCord, colCord;
    //choose disc if it's player's turn
    if (clientNum == 1 && symbol == X || clientNum == 2 && symbol == O) {
        if (optionStack.getAmount()) {
            optionStack.isRepeat();
            cout << (char) symbol << ": It's your move." << endl << "Your possible moves: ";
            for (int i = 0; i < optionStack.getAmount(); i++) {
                cout << "(" << optionStack.getDisc(i).getRowLocation() << ","
                     << optionStack.getDisc(i).getColumnLocation()
                     << ") ";
            }
            cout << endl << endl << "Please enter your move row,col:";
            while (true) {
                char input[50];
                cin.getline(input, 50);
                fromInputToDisc(input);
                rowCord = myChoise.getRowLocation();
                colCord = myChoise.getColumnLocation();
                if (optionStack.appear(myChoise)) {
                    int n = write(clientSocket, &rowCord, sizeof(rowCord));
                    if (n == -1) {
                        throw "Error writing arg1to socket";
                    }
                    n = write(clientSocket, &colCord, sizeof(colCord));
                    if (n == -1) {
                        throw "Error writing arg2to socket";
                    }
                    return myChoise;
                } else {
                    cout << endl << endl << "illegal move! Please enter your move row,col:";
                }
            }
        } else {
            //there is no move so sending the agreed sign - (0,0)
            int noChoise = 0;
            int n = write(clientSocket, &noChoise, sizeof(noChoise));
            if (n == -1) {
                throw "Error writing arg1to socket";
            }
            n = write(clientSocket, &noChoise, sizeof(noChoise));
            if (n == -1) {
                throw "Error writing arg2to socket";
            }
            return myChoise;
        }
        //updating the choise of the other player
    } else {
        if(optionStack.getAmount())
            cout << "waiting for other player's move...\n";

        int n = read(clientSocket, &rowCord, sizeof(rowCord));
        if (n == -1) {
            throw "Error writing arg1to socket";
        }
        n = read(clientSocket, &colCord, sizeof(colCord));
        if (n == -1) {
            throw "Error writing arg2to socket";
        }
        myChoise.setDisc(rowCord, colCord);
        return myChoise;
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
    myChoise.setDisc(0,0);
}
void ClientPlayer::gameOver() {
    int over = -2;
    int n = write(clientSocket, &over, sizeof(over));
    if (n == -1) {
        throw "Error writing arg1to socket";
    }
    n = write(clientSocket, &over, sizeof(over));
    if (n == -1) {
        throw "Error writing arg2to socket";
    }

}