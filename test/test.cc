#include <iostream>

using namespace std;

class X {
    int i;
public:
    X(int ii = 0) {
        i = ii;
    }
    int mI() {
        return i;
    }
};

int main() {
    // `X()`产生匿名的对象？
    cout << X().mI() << endl;

    return 0;
}
