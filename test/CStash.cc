#include "CLib.h"
#include <iostream>

using namespace std;

int main() {
    CStash s;
    initialize(&s, 3);
    add(&s, "abc");
    add(&s, "efg");

    cout << "s.storage = " << (s.storage) << endl;
    cout << "s.size = " << s.size << endl;
    cout << "s.quantity = " << s.quantity << endl;

    return 0;
}
