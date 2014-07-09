#include <iostream>
#include "printBinary.h"
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Must provide a number" << endl;
        exit(1);
    }
    double d = atof(argv[1]);
    cout << "&d = " << &d << endl;
    // 字节数组
    unsigned char* cp = reinterpret_cast<unsigned char*>(&d);

    for(int i = sizeof(double); i > 0; i -= 2) {
        printBinary(cp[i - 1]);
        printBinary(cp[i]);
    }
    return 0;
}
