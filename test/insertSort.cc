#include <iostream>

using namespace std;

// c++没法传递数组，只能传递数组的首元素地址
// 因为这里多传了一个n参数
void insertSort(int* A, int n) {
    for (int i = 2; i <= n; ++i) {
        int key = A[i];
        int j = i - 1;

        while (j > 0 && A[j] < key) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }
}

int main() {
    // 第一位预留
    // 1 ~ 6存储待排序数据
    int s[7] = {-1, 5, 2, 4, 6, 1, 3};
    insertSort(s, 6);

    for (int i = 1; i <= 6; ++i)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    return 0;
}
