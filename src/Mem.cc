#include "Mem.h"
#include <cstring>
#include <iostream>

using namespace std;

class MyString {
    Mem* buf;
public:
    MyString();
    // 字符串字面量不能赋值给`char*`，而应该是`const char*`
    MyString(const char* str);
    ~MyString();
    void concat(const char* str);
    void print(ostream &os);
};

MyString::MyString() {
    buf = 0;
}

MyString::MyString(const char* str) {
    buf = new Mem(strlen(str) + 1);
    strcpy((char*)buf->pointer(), str);
}

void MyString::concat(const char* str) {
    if (!buf) {
        buf = new Mem;
    }

    strcat((char*)buf->pointer(buf->mSize() + strlen(str) + 1), str);
}

void MyString::print(ostream& os) {
    if (!buf) {
        return;
    }
    os << buf->pointer() << endl;
}

MyString::~MyString() {
    // for `new`, use `delete``
    delete buf;
}

int main() {
    MyString s("My test string");
    s.print(cout);
    return 0;
}
