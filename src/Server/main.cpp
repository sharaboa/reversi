//
// Or Sharabi 312530496
//Sahar levi 203405147
//

#include <iostream>
#include <cstdlib>
#include "Server.h"
#include "CommandManager.h"
using namespace std;
int main() {

    Server server;

    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}