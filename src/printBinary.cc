#include <iostream>
#include "printBinary.h"

void printBinary(const unsigned char val) {
    for(int i = 7; i >= 0; i--) {
        if (val & (i << i)) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }

    std::cout << " ";
}
