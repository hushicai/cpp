// 数组循环右移算法
// 三次字符串反转法
// 线性时间右移
// O(2n) ~ O(n)
#include <iostream>

using namespace std;

void reverse(char* s, int b, int e) 
{
    for (; b < e; b++, e--) 
    {
        char temp = s[b];
        s[b] = s[e];
        s[e] = temp;
    }
}

void RightShift(char* s, int k) 
{
    int n = strlen(reinterpret_cast<const char*>(s));
    k = (k % n + n) % n;
    reverse(s, 0, n - k - 1);
    reverse(s, n - k, n - 1);
    reverse(s, 0, n - 1);
}

int main() 
{
    char s[] = "abcdefghijk";
    RightShift(s, 3);
    cout << s << endl;
    return 0;
}
