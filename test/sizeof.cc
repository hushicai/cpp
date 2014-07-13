#include <iostream>

using namespace std;

struct A {
    int i[100];
};

struct B {
    void f();
};

void B::f() {}

int main() 
{
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(char) = " << sizeof(char) << endl;
    cout << "sizeof(float) = " << sizeof(float) << endl;
    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof struct A = " << sizeof(A) << endl;
    cout << "sizeof struct B = " << sizeof(B) << endl;
    return 0;
}
