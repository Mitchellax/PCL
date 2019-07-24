/*
L1-009. N个数求和
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
本题的要求很简单，就是求N个数字的和。麻烦的是，这些数字是以有理数“分子/分母”的形式给出的，你输出的和也必须是有理数的形式。

输入格式：

输入第一行给出一个正整数N（<=100）。随后一行按格式“a1/b1 a2/b2 ...”给出N个有理数。题目保证所有分子和分母都在长整型范围内。另外，负数的符号一定出现在分子前面。

输出格式：

输出上述数字和的最简形式 —— 即将结果写成“整数部分 分数部分”，其中分数部分写成“分子/分母”，要求分子小于分母，且它们没有公因子。如果结果的整数部分为0，则只输出分数部分。

输入样例1：
5
2/5 4/15 1/30 -2/60 8/3
输出样例1：
3 1/3
输入样例2：
2
4/3 2/3
输出样例2：
2
输入样例3：
3
1/3 -1/6 1/8
输出样例3：
7/24
*/

#include <cstdio>
#include <cmath>
using namespace std;
int n;
bool neg = 0, chk = 1;
long long num[100][2];
inline long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
inline long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld/%lld", &num[i][0], &num[i][1]);
    for (int i = 0; i < n-1; i++)
    {
        long long t_lcm = lcm(num[i][1], num[i+1][1]);
        num[i+1][0] = num[i+1][0] * (t_lcm/num[i+1][1]) + num[i][0] * (t_lcm/num[i][1]);
        num[i+1][1] = t_lcm;
    }
    long long t_gcd = gcd(num[n-1][0], num[n-1][1]);
    if (num[n-1][0] < 0)
    {
        neg = 1;
        num[n-1][0] = abs(num[n-1][0]);
    }
    while (t_gcd != 1)
    {
        num[n-1][0] /= t_gcd;
        num[n-1][1] /= t_gcd;
        t_gcd = gcd(num[n-1][0], num[n-1][1]);
    }
    if (neg)
        num[n-1][0] = -num[n-1][0];
    if (num[n-1][0] % num[n-1][1] == 0)
        printf("%lld", num[n-1][0]/num[n-1][1]);
    else
    {
        if (num[n-1][0]/num[n-1][1] != 0)
            printf("%lld", num[n-1][0]/num[n-1][1]), chk = 0;
        num[n-1][0] %= num[n-1][1];
        if (num[n-1][0] != 0)
        {
            if (num[n-1][0] < 0)
            {
                neg = 1;
                num[n-1][0] = abs(num[n-1][0]);
            }
            while (t_gcd != 1)
            {
                num[n-1][0] /= t_gcd;
                num[n-1][1] /= t_gcd;
                t_gcd = gcd(num[n-1][0], num[n-1][1]);
            }
            if (neg)
                num[n-1][0] = -num[n-1][0];
            printf(chk ? "%lld/%lld": " %lld/%lld", num[n-1][0], num[n-1][1]);
        }
    }
    return 0;
}