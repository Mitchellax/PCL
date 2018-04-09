/*
L1-040. 最佳情侣身高差
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
专家通过多组情侣研究数据发现，最佳的情侣身高差遵循着一个公式：（女方的身高）×1.09=（男方的身高）。如果符合，你俩的身高差不管是牵手、拥抱、接吻，都是最和谐的差度。

下面就请你写个程序，为任意一位用户计算他/她的情侣的最佳身高。

输入格式：

输入第一行给出正整数N（<=10），为前来查询的用户数。随后N行，每行按照“性别 身高”的格式给出前来查询的用户的性别和身高，其中“性别”为“F”表示女性、“M”表示男性；“身高”为区间 [1.0, 3.0] 之间的实数。

输出格式：

对每一个查询，在一行中为该用户计算出其情侣的最佳身高，保留小数点后2位。

输入样例：
2
M 1.75
F 1.8
输出样例：
1.61
1.96
*/

#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	double height, aimhei;
	bool fstpas = 0;
	char sex;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		if(fstpas)
			printf("\n");
		cin >> sex;
		cin >> height;
		if(sex == 'M')
			aimhei = height / 1.09;
		else if(sex == 'F')
			aimhei = height * 1.09;
		printf("%.2lf", aimhei);
		fstpas = 1;
	}
	return 0;
}