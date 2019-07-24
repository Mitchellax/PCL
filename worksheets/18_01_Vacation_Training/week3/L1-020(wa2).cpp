/*
L1-020. 帅到没朋友
时间限制
200 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
当芸芸众生忙着在朋友圈中发照片的时候，总有一些人因为太帅而没有朋友。本题就要求你找出那些帅到没有朋友的人。

输入格式：

输入第一行给出一个正整数N（<=100），是已知朋友圈的个数；随后N行，每行首先给出一个正整数K（<=1000），为朋友圈中的人数，然后列出一个朋友圈内的所有人——为方便起见，每人对应一个ID号，为5位数字（从00000到99999），ID间以空格分隔；之后给出一个正整数M（<=10000），为待查询的人数；随后一行中列出M个待查询的ID，以空格分隔。

注意：没有朋友的人可以是根本没安装“朋友圈”，也可以是只有自己一个人在朋友圈的人。虽然有个别自恋狂会自己把自己反复加进朋友圈，但题目保证所有K超过1的朋友圈里都至少有2个不同的人。

输出格式：

按输入的顺序输出那些帅到没朋友的人。ID间用1个空格分隔，行的首尾不得有多余空格。如果没有人太帅，则输出“No one is handsome”。

注意：同一个人可以被查询多次，但只输出一次。

输入样例1：
3
3 11111 22222 55555
2 33333 44444
4 55555 66666 99999 77777
8
55555 44444 10000 88888 22222 11111 23333 88888
输出样例1：
10000 88888 23333
输入样例2：
3
3 11111 22222 55555
2 33333 44444
4 55555 66666 99999 77777
4
55555 44444 22222 11111
输出样例2：
No one is handsome
*/

#include <cstdio>
#include <algorithm>
bool chk[100001];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int row, com = 0, temp = 1;
		scanf("%d", &row);
		int num[row];
		for (int j = 0; j < row; j++)
			scanf("%d", &num[j]);
		std::sort(num, num + row);
		while(temp)
		{
			temp = 0;
			for (int j = 1; j < row; j++)
			{
				if(num[j - 1] == num[j] && num[j] != 100000)
				{
					temp++;
					num[j] = 100000;
				}
			}
			com += temp;
		}
		if(row - com > 1)
		{
			for (int j = 0; j < row; j++)
				chk[num[j]] = 1;
		}
	}
	int query;
	scanf("%d", &query);
	int res[query];
	int count = 0;
	for (int i = 0; i < query; i++)
	{
		int t;
		scanf("%d", &t);
		if (!chk[t])
		{
			chk[t] = 1;
			res[count] = t;
			count++;
		}
	}
	if (count == 0)
	{
		printf("No one is handsome");
		return 0;
	}
	for (int i = 0; i < count-1; i++)
		printf("%d ", res[i]);
	printf("%d", res[count-1]);
	return 0;
}