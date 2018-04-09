#include <stdio.h>
#include <windows.h>


int main(int argc, char const *argv[])
{
	int i, i_t;
	char array[4] = "-/|\\";
	for (i = 1; i <= 100; i++)
	{
		printf("loading");
		printf("  %d%%  ", i);
		if(i < 10)
			printf(" ");
		printf(" %c  ", array[i % 4]);
		for (i_t = 0; i_t < i / 10; i_t++)
			printf("*");
		for (i_t = 0; i_t < 10 - (i / 10); i_t++)
			printf("-");
		Sleep(100);
		printf("\r");
	}
	printf("\r");
	printf("Already loaded                                    \n");
	return 0;
}