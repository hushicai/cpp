#include <iostream>

int main() {
    int a[] = {1, 2, 2, 1, 3, 4, 5, 3, 5};
    int result = 0;
    for (const auto k: a) {
        result ^= k; 
    }
    std::cout << result << std::endl;
    return 0;
}
