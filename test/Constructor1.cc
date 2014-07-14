#include <iostream>

using namespace std;

class Tree {
    int height;
    public:
        Tree(int initHeight);
        ~Tree();
        void grow(int years);
        void printSize();
};

Tree::Tree(int initHeight) {
    height = initHeight;
}

Tree::~Tree() {
    cout << "inside tree destructor" << endl;
    printSize();
}

void Tree::grow(int years) {
    height += years;
}

void Tree::printSize() {
    cout << "Tree height is " << height << endl;
}

int main() {
    cout << "before opening brace" << endl;
    {
        Tree t(12);
        cout << "after Tree creation" << endl;
        t.printSize();
        t.grow(4);
        cout << "before closing brace" << endl;
    }
    cout << "after closing brace" << endl;
    return 0;
}
