#include <stdio.h>
#include <memory.h>

int fac(int num);
int power(int num, int m);//数学库的那个在我这个低版本gcc里有问题
int interesting(int num, int aim_bit);

int main(int argc, char const *argv[])
{
	const int res_bits = 5;
	const int begin = 146;
	int i;
	for (i = begin; i < power(10, res_bits + 1); ++i)
	{
		if(i == interesting(i, res_bits))
			printf("%d\n", i);
	}
	return 0;
}

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

int power(int num, int m)
{
	if(!m)
		return 1;
	else
	{
		int i;
		int temp = num;
		for (i = 1; i < m; i++)
			num = num * temp;
		return num;
	}
}

int interesting(int num, int aim_bit)
{
	int i, sum = 0, if_zero = 0;
	int bits[aim_bit];
	memset(bits, 10, sizeof(bits));
	for (i = 0; i < aim_bit; i++)
	{
		bits[aim_bit - i - 1] = num % 10;
		num = num / 10;
	}
	for (i = 0; i < aim_bit; i++)
	{
		if (bits[i] && !if_zero)
			if_zero = 1;
		if (bits[i] < 10 && if_zero)
		{
			sum += fac(bits[i]);
		}
	}
	return sum;
}