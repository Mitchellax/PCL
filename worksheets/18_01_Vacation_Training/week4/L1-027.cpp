/*
L1-027. 出租
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
下面是新浪微博上曾经很火的一张图：

（假装这是图，原图：http://nos.patest.cn/li_o9webi2nzmq.jpg）
---------------------------------------------------------------------
|								出租									|
|	升景坊单间短期出租4个月，550元/月（水电煤公摊，网费35元/月）。空		|
|调、卫生间、厨房齐全。屋内均是IT行业人士，喜欢安静。所以要求来租者最		|
|好是同行或者刚毕业的年轻人，爱干净、安静。								|
|	有意者电联。														|
|																	|
|	联系人：成先生													|
|																	|
|	联系方式：请阅读代码												|
|	int[] arr = new int[]{8,2,1,0,3};								|
|	int[] index = new int[]{2,0,3,2,4,0,1,3,2,3,3};					|
|	String tel = "";												|
|		for(int i : index){											|
|			tel+= arr[i];											|
|		}															|
|	System.out.println("联系方式："+tel);							|
---------------------------------------------------------------------

一时间网上一片求救声，急问这个怎么破。其实这段代码很简单，index数组就是arr数组的下标，index[0]=2 对应 arr[2]=1，index[1]=0 对应 arr[0]=8，index[2]=3 对应 arr[3]=0，以此类推…… 很容易得到电话号码是18013820100。

本题要求你编写一个程序，为任何一个电话号码生成这段代码 —— 事实上，只要生成最前面两行就可以了，后面内容是不变的。

输入格式：

输入在一行中给出一个由11位数字组成的手机号码。

输出格式：

为输入的号码生成代码的前两行，其中arr中的数字必须按递减顺序给出。

输入样例：
18013820100
输出样例：
int[] arr = new int[]{8,3,2,1,0};
int[] index = new int[]{3,0,4,3,1,0,2,4,3,4,4};
*/

#include <cstdio>
bool wt[10], fstput;
int sx[11];
int main(int argc, char const *argv[])
{
	int num[11];
	char temp;
	for (int i = 0; i < 11; i++)
	{
		scanf("%c", &temp);
		num[i] = temp - '0';
		wt[temp - '0'] = 1;
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 9; j >= 0; j--)
		{
			if(wt[j])
			{
				sx[i]++;
				if(num[i] == j)
				{
					sx[i]--;
					break;
				}
			}
		}
	}
	printf("int[] arr = new int[]{");
	for (int i = 9; i >= 0; i--)
	{
		if(wt[i])
		{
			if(fstput)
				printf(",");
			printf("%d", i);
			fstput = 1;
		}
	}
	printf("};\nint[] index = new int[]{");
	fstput = 0;
	for (int i = 0; i < 11; i++)
	{
		if(fstput)
			printf(",");
		printf("%d", sx[i]);
		fstput = 1;
	}
	printf("};");
	return 0;
}
