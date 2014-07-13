#include <iostream>

using namespace std;

struct X;

int main() {
    int* p;
    cout << sizeof(p) << endl;

    X* x;
    cout << sizeof(x) << endl;

    return 0;
}
