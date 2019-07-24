/*
L1-013. 计算阶乘和
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
对于给定的正整数N，需要你计算 S = 1! + 2! + 3! + ... + N!。

输入格式：

输入在一行中给出一个不超过10的正整数N。

输出格式：

在一行中输出S的值。

输入样例：
3
输出样例：
9
*/

#include <cstdio>
int main(int argc, char const *argv[])
{
  int n;
  long long NUM = 0, temp = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    temp = 1;
    for (int t = 1; t <= i; t++)
      temp *= t;
    NUM += temp;
  }
  printf("%lld", NUM);
  return 0;
}
