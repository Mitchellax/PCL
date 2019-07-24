/*
L1-048. 矩阵A乘以B
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
给定两个矩阵A和B，要求你计算它们的乘积矩阵AB。需要注意的是，只有规模匹配的矩阵才可以相乘。即若A有Ra行、Ca列，B有Rb行、Cb列，则只有Ca与Rb相等时，两个矩阵才能相乘。

输入格式：

输入先后给出两个矩阵A和B。对于每个矩阵，首先在一行中给出其行数R和列数C，随后R行，每行给出C个整数，以1个空格分隔，且行首尾没有多余的空格。输入保证两个矩阵的R和C都是正数，并且所有整数的绝对值不超过100。

输出格式：

若输入的两个矩阵的规模是匹配的，则按照输入的格式输出乘积矩阵AB，否则输出“Error: Ca != Rb”，其中Ca是A的列数，Rb是B的行数。

输入样例1：
2 3
1 2 3
4 5 6
3 4
7 8 9 0
-1 -2 -3 -4
5 6 7 8
输出样例1：
2 4
20 22 24 16
53 58 63 28
输入样例2：
3 2
38 26
43 -5
0 17
3 2
-11 57
99 68
81 72
输出样例2：
Error: 2 != 3
*/

#include <cstdio>
int main(int argc, char const *argv[])
{
	int Ca, Ra, Cb, Rb;
	scanf("%d %d", &Ra, &Ca);
	int A[Ra][Ca];
	for (int i = 0; i < Ra; i++)
	{
		for (int j = 0; j < Ca; j++)
			scanf("%d", &A[i][j]);
	}
	scanf("%d %d", &Rb, &Cb);
	int B[Rb][Cb];
	if(Ca != Rb)
		printf("Error: %d != %d", Ca, Rb);
	else
	{
		for (int i = 0; i < Rb; i++)
		{
			for (int j = 0; j < Cb; j++)
				scanf("%d", &B[i][j]);
		}
		printf("%d %d\n", Ra, Cb);
		for (int i = 0; i < Ra; i++)
		{
			if(i)
				printf("\n");
			for (int j = 0; j < Cb; j++)
			{
				int temp = 0;
				for (int k = 0; k < Ca; k++)
					temp += A[i][k] * B[k][j];
				if(!j)
					printf("%d", temp);
				else
					printf(" %d", temp);
			}
		}
	}
	return 0;
}