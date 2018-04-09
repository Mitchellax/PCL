/*
L1-039. 古风排版
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
中国的古人写文字，是从右向左竖向排版的。本题就请你编写程序，把一段文字按古风排版。

输入格式：

输入在第一行给出一个正整数N（<100），是每一列的字符数。第二行给出一个长度不超过1000的非空字符串，以回车结束。

输出格式：

按古风格式排版给定的字符串，每列N个字符（除了最后一列可能不足N个）

输入样例：
4
This is a test case
输出样例：
asa T
st ih
e tsi
 ce s
*/

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string str, temp;
int main(int argc, char const *argv[])
{
	int num, con, spanum;
	bool fstpa = 0;
	cin >> num;
	getline(cin, temp);
	getline(cin, str);
	if(str.length() % num)
		spanum = num - str.length() % num;
	else
		spanum = 0;
	for (int i = 0; i < spanum; i++)
		str = str + " ";
	con = str.length() / num;
	for (int i = 0; i < num; i++)
	{
		if(fstpa)
			printf("\n");
		for (int j = 1; j <= con; j++)
			printf("%c", str[str.length() + i - num * j ]);
		fstpa = 1;
	}
	return 0;
}