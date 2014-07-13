#include "CLib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main() {
    CStash intStash, stringStash;
    char* cp;
    ifstream in;
    string line;
    const int bufzie = 80;
    initialize(&intStash, sizeof(int));
    for(int i = 0; i < 100; i++) {
        add(&intStash, &i);
    }
    for(int i = 0; i < count(&intStash); i++) {
        cout << "fetch(&intStash, " << i << ") = " 
            << *(int*)fetch(&intStash, i)
            <<endl;
    }
    return 0;
}
