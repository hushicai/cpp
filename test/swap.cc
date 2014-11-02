#include <iostream>
#include <string>

void swap(char& c1, char& c2) {
    char t = c1;
    c1 = c2;
    c2 = t;
}

int main() {
    std::string str = "abc";
    swap(str[0], str[2]);
    std::cout << str << std::endl;
    return 0;
}
