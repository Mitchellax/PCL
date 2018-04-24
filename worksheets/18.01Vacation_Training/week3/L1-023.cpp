/*
L1-023. 输出GPLT
时间限制
150 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“GPLTGPLT....”这样的顺序输出，并忽略其它字符。当然，四种字符（不区分大小写）的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按GPLT的顺序打印，直到所有字符都被输出。

输入格式：

输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：

在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
pcTclnGloRgLrtLhgljkLhGFauPewSKgt
输出样例：
GPLTGPLTGLTGLGLL
*/

#include <cstdio>
#include <string>
#include <iostream>
int main(int argc, char const *argv[])
{
	std::string str;
	int GPLT[4] = {0, 0, 0, 0};
	std::cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		switch(str.at(i))
		{
			case 'G':
				GPLT[0]++;
				break;
			case 'P':
				GPLT[1]++;
				break;
			case 'L':
				GPLT[2]++;
				break;
			case 'T':
				GPLT[3]++;
				break;
			case 'g':
				GPLT[0]++;
				break;
			case 'p':
				GPLT[1]++;
				break;
			case 'l':
				GPLT[2]++;
				break;
			case 't':
				GPLT[3]++;
				break;
		}
	}
	while(GPLT[0] || GPLT[1] || GPLT[2] || GPLT[3])
	{
		if(GPLT[0])
		{
			printf("G");
			GPLT[0]--;
		}
		if(GPLT[1])
		{
			printf("P");
			GPLT[1]--;
		}
		if(GPLT[2])
		{
			printf("L");
			GPLT[2]--;
		}
		if(GPLT[3])
		{
			printf("T");
			GPLT[3]--;
		}
	}
	return 0;
}