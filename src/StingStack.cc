#include <iostream>
#include <string>

using namespace std;

class StringStack {
    static const int size = 100;
    const string* stack[size];
    int index;
public:
    StringStack();
    void push(const string* s);
    const string* pop();
};

StringStack::StringStack():index(0) {
    memset(stack, 0, size * sizeof(string*));
}

void StringStack::push(const string* s) {
    if (index < size) {
        stack[index++] = s;
    }
}

const string* StringStack::pop() {
    if (index > 0) {
        const string* rv = stack[--index];
        stack[index] = 0;
        return rv;
    }

    return 0;
}

string iceCream[] = {
    "test1",
    "test2",
    "test3"
};

const int iCsz = sizeof(iceCream) / sizeof(*iceCream);

int main() {
    StringStack ss;
    for(int i = 0; i < iCsz; i++) {
        ss.push(&iceCream[i]);
    }
    const string* cp;
    while((cp = ss.pop()) != 0) {
        cout << *cp << endl;
    }
    return 0;
}
