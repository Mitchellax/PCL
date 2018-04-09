/*
L1-035. 情人节
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

以上是朋友圈中一奇葩贴：“2月14情人节了，我决定造福大家。第2个赞和第14个赞的，我介绍你俩认识…………咱三吃饭…你俩请…”。现给出此贴下点赞的朋友名单，请你找出那两位要请客的倒霉蛋。

输入格式：

输入按照点赞的先后顺序给出不知道多少个点赞的人名，每个人名占一行，为不超过10个英文字母的非空单词，以回车结束。一个英文句点“.”标志输入的结束，这个符号不算在点赞名单里。

输出格式：

根据点赞情况在一行中输出结论：若存在第2个人A和第14个人B，则输出“A and B are inviting you to dinner...”；若只有A没有B，则输出“A is the only one for you...”；若连A都没有，则输出“Momo... No one is for you ...”。

输入样例1：
GaoXZh
Magi
Einst
Quark
LaoLao
FatMouse
ZhaShen
fantacy
latesum
SenSen
QuanQuan
whatever
whenever
Potaty
hahaha
.
输出样例1：
Magi and Potaty are inviting you to dinner...
输入样例2：
LaoLao
FatMouse
whoever
.
输出样例2：
FatMouse is the only one for you...
输入样例3：
LaoLao
.
输出样例3：
Momo... No one is for you ...
*/

#include <iostream>
#include <string>
using namespace std;
string people[14];
bool nonpeo, onepeo;
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 14; i++)
	{
		string temp;
		cin >> temp;
		if(temp == ".")
		{
			if(i < 2)
				nonpeo = 1;
			else
				onepeo = 1;
			break;
		}
		else
			people[i] = temp;
	}
	if(nonpeo)
		cout << "Momo... No one is for you ..." << endl;
	else if(onepeo)
		cout << people[1] << " is the only one for you..." << endl;
	else
		cout << people[1] << " and " << people[13] << " are inviting you to dinner..." << endl;
	return 0;
}