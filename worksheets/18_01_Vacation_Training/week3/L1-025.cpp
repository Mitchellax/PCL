/*
L1-025. 正整数A+B
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
本题的目标很简单，就是求两个正整数A和B的和，其中A和B都在区间[1,1000]。稍微有点麻烦的是，输入并不保证是两个正整数。

输入格式：

输入在一行给出A和B，其间以空格分开。问题是A和B不一定是满足要求的正整数，有时候可能是超出范围的数字、负数、带小数点的实数、甚至是一堆乱码。

注意：我们把输入中出现的第1个空格认为是A和B的分隔。题目保证至少存在一个空格，并且B不是一个空字符串。

输出格式：

如果输入的确是两个正整数，则按格式“A + B = 和”输出。如果某个输入不合要求，则在相应位置输出“?”，显然此时和也是“?”。

输入样例1：
123 456
输出样例1：
123 + 456 = 579
输入样例2：
22. 18
输出样例2：
? + 18 = ?
输入样例3：
-100 blabla bla...33
输出样例3：
? + ? = ?
*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string num;
	int mkspace;
	bool ifnw1 = 0, ifnw2 = 0, ifmkspace = 0;
	getline(cin,num);
	bool chk[num.length()];
	for (int i = 0; i < num.length(); i++)
	{
		if(num.at(i) > '9' || num.at(i) < '0')
		{
			if(num.at(i) == ' ' && !ifmkspace)
			{
				mkspace = i;
				ifmkspace = 1;
			}
			else if(!ifmkspace)
			{
				ifnw1 = true;
				printf("? + ");
			}
			else if(ifmkspace)
			{
				ifnw2 = true;
				printf("? = ");
			}
		}
		else
		{
			if(!ifmkspace)
			{
				if(!ifnw1 && num.at(i) == '0')
				{
					ifnw1 = true;
					printf("? + ");
				}
				else if(num.at(i) > '0')
					ifnw1 = true;
			}
			else
			{
				if(!ifnw2 && num.at(i) == '0')
				{
					ifnw2 = true;
					printf("? = ");
				}
				else if(num.at(i) > '0')
					ifnw2 = true;
			}	

		}
		
	}
	return 0;
}