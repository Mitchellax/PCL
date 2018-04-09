/*
 L1-003. 个位数统计
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
 给定一个k位整数N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。
 
 输入格式：
 
 每个输入包含1个测试用例，即一个不超过1000位的正整数N。
 
 输出格式：
 
 对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。
 
 输入样例：
 100311
 输出样例：
 0:2
 1:3
 3:1
*/

#include <cstdio>
int main(int argc, char const *argv[])
{
	char numbers[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char temp = 0;
	while(~scanf("%c", &temp))
	{
		switch(temp)
		{
			case '0':
				numbers[0]++;
				break;
			case '1':
				numbers[1]++;
				break;
			case '2':
				numbers[2]++;
				break;
			case '3':
				numbers[3]++;
				break;
			case '4':
				numbers[4]++;
				break;
			case '5':
				numbers[5]++;
				break;
			case '6':
				numbers[6]++;
				break;
			case '7':
				numbers[7]++;
				break;
			case '8':
				numbers[8]++;
				break;
			case '9':
				numbers[9]++;
				break;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		if(numbers[i] != 0)
			printf("%d:%d\n", i, numbers[i]);
	}
	return 0;
}