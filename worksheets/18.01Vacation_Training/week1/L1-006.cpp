/*
L1-006. 连续因子
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
一个正整数N的因子中可能存在若干连续的数字。例如630可以分解为3*5*6*7，其中5、6、7就是3个连续的数字。给定任一正整数N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：

输入在一行中给出一个正整数N（1<N<231）。

输出格式：

首先在第1行输出最长连续因子的个数；然后在第2行中按“因子1*因子2*……*因子k”的格式输出最小的连续因子序列，其中因子按递增顺序输出，1不算在内。

输入样例：
630
输出样例：
3
5*6*7
*/


#include <cstdio>
#include <cmath>
int main()
{
    int n;
    scanf("%d", &n);
    int t_sqrt = sqrt(n)+1;
    int count = 0, t_count;
    int init = -1, init_len = 0;
    for (int i = 2; i < t_sqrt; i++)
    {
        int t_n = n;
        t_count = 0;
        int j = i;
        while(t_n % j == 0)
        {
            t_n /= j;
            t_count++;
            j++;
        }
        if (t_count > count)
        {
            count = t_count;
            init = i;
            init_len = t_count;
        }
    }
    if (init == -1)
        printf("1\n%d", n);
    else
    {
        printf("%d\n%d", count, init);
        for (int i = 1; i < init_len; i++)
            printf("*%d", init+i);
    }
    return 0;
}
