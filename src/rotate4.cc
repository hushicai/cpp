//递归，    
//感谢网友Bluesmic提供的思路    
    
//copyright@ yansha 2011.04.19    
//July，updated，2011.04.20.    
#include <iostream>    
using namespace std;    
    
void rotate(string &str, int n, int m, int head, int tail, bool flag)    
{    
    //n 待处理部分的字符串长度，m：待处理部分的旋转长度    
    //head：待处理部分的头指针，tail：待处理部分的尾指针    
    //flag = true进行左旋，flag = false进行右旋    
        
    // 返回条件    
    if (head == tail || m <= 0)    
        return;    
        
    if (flag == true)    
    {    
        int p1 = head;    
        int p2 = head + m;  //初始化p1，p2    
            
        //1、左旋：对于字符串abc def ghi gk，    
        //将abc右移到def ghi gk后面，此时n = 11，m = 3，m’ = n % m = 2;    
        //abc def ghi gk -> def ghi abc gk    
        //（相信，经过上文中那么多繁杂的叙述，此类的转换过程，你应该是了如指掌了。）    
            
        int k = (n - m) - n % m;   //p1，p2移动距离，向右移六步    
    
        /*---------------------  
        解释下上面的k = (n - m) - n % m的由来：  
        yansha：  
        以p2为移动的参照系：  
        n-m 是开始时p2到末尾的长度，n%m是尾巴长度  
        (n-m)-n%m就是p2移动的距离  
        比如 abc def efg hi  
        开始时p2->d,那么n-m 为def efg hi的长度8，  
        n%m 为尾巴hi的长度2，  
        因为我知道abc要移动到hi的前面，所以移动长度是  
        (n-m)-n%m = 8-2 = 6。  
        */    
            
        for (int i = 0; i < k; i++, p1++, p2++)    
            swap(str[p1], str[p2]);    
            
        rotate(str, n - k, n % m, p1, tail, false);  //flag标志变为false，结束左旋，下面，进入右旋    
    }    
    else    
    {    
        //2、右旋：问题变成gk左移到abc前面，此时n = m’ + m = 5，m = 2，m’ = n % m 1;    
        //abc gk -> a gk bc    
            
        int p1 = tail;    
        int p2 = tail - m;    
            
        // p1，p2移动距离，向左移俩步    
        int k = (n - m) - n % m;    
            
        for (int i = 0; i < k; i++, p1--, p2--)    
            swap(str[p1], str[p2]);    
            
        rotate(str, n - k, n % m, head, p1, true);  //再次进入上面的左旋部分，    
        //3、左旋：问题变成a右移到gk后面，此时n = m’ + m = 3，m = 1，m’ = n % m = 0;    
        //a gk bc-> gk a bc。 由于此刻，n % m = 0，满足结束条件，返回结果。    
    
    }    
}    
    
int main()    
{    
    int i=3;    
    string str = "abcdefghijk";    
    int len = str.length();    
    rotate(str, len, i % len, 0, len - 1, true);    
    cout << str.c_str() << endl;   //转化成字符数组的形式输出    
    return 0;    
}    
