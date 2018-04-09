/*
L1-011. A-B
时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
本题要求你计算A-B。不过麻烦的是，A和B都是字符串 —— 即从字符串A中把字符串B所包含的字符全删掉，剩下的字符组成的就是字符串A-B。

输入格式：

输入在2行中先后给出字符串A和B。两字符串的长度都不超过104，并且保证每个字符串都是由可见的ASCII码和空白字符组成，最后以换行符结束。

输出格式：

在一行中打印出A-B的结果字符串。

输入样例：
I love GPLT!  It's a fun game!
aeiou
输出样例：
I lv GPLT!  It's  fn gm!
*/

//下标法赛高！！！

#include <cstdio>
#include <cstring>
bool chk[128];
int main()
{
    char arr[10010], brr[10010];
    gets(arr);
    gets(brr);
    int len = strlen(brr);
    for (int i = 0; i < len; i++)
        chk[brr[i]] = 1;
    len = strlen(arr);
    for (int i = 0; i < len; i++)
        if (!chk[arr[i]])
            putchar(arr[i]);
    return 0;
}