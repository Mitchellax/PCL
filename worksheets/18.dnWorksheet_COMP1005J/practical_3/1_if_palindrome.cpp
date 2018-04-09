#include <cstdio>

int reverse (int num,int s = 0)
{
	s = 10 * s + num % 10;
	if (num > 10) 
		reverse (num / 10, s);
	else return s;
}

int main(int argc, char const *argv[])
{
	int num;
	scanf("%d", &num);
	if(num == reverse(num))
		printf("Yes");
	else
		printf("No");
	return 0;
}