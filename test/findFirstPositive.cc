#include <iostream>

using namespace std;

void swap(int* A,int b, int e) {
    int temp = A[b];
    A[b] = A[e];
    A[e] = temp;
}

int main() {
    const int n = 3;
    int A[] = {-1, -1, -1};
    for (int i = 0; i < n; ++i) {
        int k = A[i] - 1;
        // 循环处理，直至位置i上的元素已经处理合理的位置上
        if (k >=0 && k < n && k != i && A[k] != A[i]) {
            swap(A, i, k);
            i--;
        }
    }

    int miss = n + 1;
    for (int i = 0; i < n; ++i) {
        if (A[i] != i + 1) {
            miss = i + 1;
            break;
        }
    }
    cout << miss << endl;
    return 0;
}
