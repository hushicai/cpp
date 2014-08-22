// copyright@July、颜沙    
// 最终代码，July，updated again，2011.04.17。
#include <iostream>    
#include <string>    
using namespace std;    
    
void rotate(string &str, int m)    
{    
    if (str.length() == 0 || m <= 0)    
        return;    
        
    int n = str.length();    
        
    if (m % n <= 0)    
        return;    
        
    int p1 = 0, p2 = m;    
    // 可以整体往前移的次数
    int k = (n - m) - n % m;    
        
    // 交换p1，p2指向的元素，然后移动p1，p2    
    while (k --)     
    {    
        swap(str[p1], str[p2]);    
        p1++;    
        p2++;    
    }    
        
    // 处理尾部
    int r = n - p2;    
    while (r--)    
    {    
        int i = p2;    
        while (i > p1)    
        {    
            swap(str[i], str[i-1]);    
            i--;    
        }    
        p1++;    
        p2++;    
    }    
}    
    
int main()       
{       
    string ch="abcdefghijk";       
    rotate(ch,3);       
    cout<<ch<<endl;       
    return 0;          
}      
