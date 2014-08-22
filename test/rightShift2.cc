#include <iostream>

using namespace std;

void rightShift(char* a, int n) {
    // 字符长度
    int l = strlen(a);
    char* b = new char[l];
    // 剩余字符长度
    int r = l - n;
    // 首先将剩余的字符拷贝拷贝到新数组
    strcpy(b, a + n);
    // 再将待移位的字符拷贝到新数组的后面
    strncpy(b + r, a, n);
    b[l] = '\0';
    strcpy(a, b);
}

int main() 
{
    char s[] = "abcdefghijk";
    rightShift(s, 3);
    cout << s << endl;
    return 0;
}
