#include <iostream>

int main() {
    int a[] = {1, 2, 2, 1, 3, 4, 5, 3, 5};
    int result = 0;
    int size = sizeof(a) / sizeof(*a);
    for (int i = 0; i < size; i++) {
        result ^= a[i]; 
    }
    std::cout << result << std::endl;
    return 0;
}
