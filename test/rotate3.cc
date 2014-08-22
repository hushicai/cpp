/*  
 * myinvert2.cpp  
 *  
 *  Created on: 2011-5-11  
 *      Author: BigPotato  
 */    
#include<iostream>    
#include<string>    
#define positiveMod(m,n) ((m) % (n) + (n)) % (n)    
    
/*  
 *左旋字符串str，m为负数时表示右旋abs（m）个字母  
 */    
void rotate(std::string &str, int m) {    
    if (str.length() == 0)    
        return;    
    int n = str.length();    
    //处理大于str长度及m为负数的情况,positiveMod可以取得m为负数时对n取余得到正数    
    m = positiveMod(m,n);    
    if (m == 0)    
        return;    
    //    if (m % n <= 0)    
    //        return;    
    int p1 = 0, p2 = m;    
    //p2当前所指和之后的m-1个字母共m个字母，就可以和p2前面的m个字母交换。    
    while (p2 + m - 1 < n) {    
        int round = m;    
        while (round--) {    
            std::swap(str[p1], str[p2]);    
            p1++;    
            p2++;    
        }    
    }    
    //剩下的不足m个字母逐个交换    
    int r = n - p2;    
    while (r--) {    
        int i = p2;    
        while (i > p1) {    
            std::swap(str[i], str[i - 1]);    
            i--;    
        }    
        p2++;    
        p1++;    
    }    
}    
    
//测试    
int main() {    
    //    std::cout << ((-15) % 7 + 7) % 7 << std::endl;    
    //    std::cout << (-15) % 7 << std::endl;    
    std::string ch = "abcdefg";    
    int len = ch.length();    
    for (int m = -2 * len; m <= len * 2; m++) {    
        //由于传给rotate的是string的引用，所以这里每次调用都用了一个新的字符串    
        std::string s = "abcdefg";    
        rotate(s, m);    
        std::cout << positiveMod(m,len) << ": " << s << std::endl;    
    }    
     
    return 0;    
}   
