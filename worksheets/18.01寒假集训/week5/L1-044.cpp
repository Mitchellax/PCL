/*
L1-044. 稳赢
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
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

（规则易懂，不文字化。原图：http://nos.patest.cn/of_oo9zfrbo2e3.jpg）

现要求你编写一个稳赢不输的程序，根据对方的出招，给出对应的赢招。但是！为了不让对方输得太惨，你需要每隔K次就让一个平局。

输入格式：

输入首先在第一行给出正整数K（<=10），即平局间隔的次数。随后每行给出对方的一次出招：“ChuiZi”代表“锤子”、“JianDao”代表“剪刀”、“Bu”代表“布”。“End”代表输入结束，这一行不要作为出招处理。

输出格式：

对每一个输入的出招，按要求输出稳赢或平局的招式。每招占一行。

输入样例：
2
ChuiZi
JianDao
Bu
JianDao
Bu
ChuiZi
ChuiZi
End
输出样例：
Bu
ChuiZi
Bu
ChuiZi
JianDao
ChuiZi
Bu
*/


#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int N, i = 0;
	string zhaoshi;
	cin >> N;
	while(1)
	{
		cin >> zhaoshi;
		if(zhaoshi == "End")
			break;
		i++;
		i %= N + 1;
		if(!i)
			cout << zhaoshi << endl;
		else if(zhaoshi == "ChuiZi")
			cout << "Bu" << endl;
		else if(zhaoshi == "Bu")
			cout << "JianDao" << endl;
		else if(zhaoshi == "JianDao")
			cout << "ChuiZi" << endl;
	}
	return 0;
}