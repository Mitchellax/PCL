/*
L1-010. 比较大小
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
杨起帆（浙江大学城市学院）
本题要求将输入的任意3个整数从小到大输出。

输入格式：

输入在一行中给出3个整数，其间以空格分隔。

输出格式：

在一行中将3个整数从小到大输出，其间以“->”相连。

输入样例：
4 2 8
输出样例：
2->4->8
*/

#include <cstdio>
void EXcmp(long long * a, long long * b)
{
	if(*a > *b)
	{
		long long temp = *a;
		*a = *b;
		*b = temp;
	}
	return;
}
int main(int argc, char const *argv[])
{
	long long num[3];
	scanf("%lld %lld %lld", &num[0], &num[1], &num[2]);
	EXcmp(&num[1], &num[2]);
	EXcmp(&num[0], &num[1]);
	EXcmp(&num[1], &num[2]);
	printf("%lld->%lld->%lld\n", num[0], num[1], num[2]);
	return 0;
}