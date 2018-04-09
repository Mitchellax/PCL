#include <stdio.h>

void func_1(int * P)
{
	*P = 200;
}

int main(int argc, char const *argv[])
{
	int x = 100;
	printf("x is %d\n", x);
	func_1(&x);
	printf("x is %d\n", x);
	return 0;
}