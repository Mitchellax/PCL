/*
L1-012. 计算指数
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
真的没骗你，这道才是简单题 —— 对任意给定的不超过10的正整数n，要求你输出2n。不难吧？

输入格式：

输入在一行中给出一个不超过10的正整数n。

输出格式：

在一行中按照格式“2^n = 计算结果”输出2n的值。

输入样例：
5
输出样例：
2^5 = 32
*/

#include <cstdio>
#include <cmath>
int main(int argc, char const *argv[])
{
  int n;
  scanf("%d", &n);
  printf("2^%d = %d", n, (int)pow(2,n));
  return 0;
}