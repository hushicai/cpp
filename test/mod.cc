#include <iostream>

using namespace std;

// 自然数取模
// 
// 负数取模的问题：
// * 商，向零取整
// * 余数 = 被除数 - 商 x 除数

int main() {
    cout << (-2) % 5 << endl;
    return 0;
}
