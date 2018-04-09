//能给个输入的范围吗。。。。。。
#include <stdio.h>

int fac(int num)
{
	int factorial = 1;
	if(!num)
		return 1;
	else
	{
		int i;
		for (i = 2; i <= num; i++)
			factorial = factorial * i;
		return factorial;
	}
}

int main(int argc, char const *argv[])
{
	int number;
	scanf("%d", &number);
	printf("%d\n", fac(number));
	return 0;
}