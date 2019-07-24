//这儿就不考虑大数据运算了，输入加个范围不行吗？郁闷。。。。。。

#include <stdio.h>

int perfect(int num)
{
	int i, sum = 0;
	for (i = 1; i <= num / 2 + 1; i++)
	{
		if(num % i == 0)
			sum += i;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int number, sum;
	scanf("%d", &number);
	sum = perfect(number);
	if(number == sum)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
