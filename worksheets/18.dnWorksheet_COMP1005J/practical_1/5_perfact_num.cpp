#include <cstdio>
#include <cmath>

int main(int argc, char const *argv[])
{
	int num, sum = 0;
	scanf("%d", &num);
	int temp = num / 2;
	for (int i = 1; i <= temp; i++)
	{
		if(!(num % i))
			sum += i;
	}
	if(num == sum)
		printf("yes");
	else
		printf("no");
	return 0;
}