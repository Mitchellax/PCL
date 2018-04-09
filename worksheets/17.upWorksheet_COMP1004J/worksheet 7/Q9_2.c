#include <stdio.h>
#include <memory.h>

int main(int argc, char const *argv[])
{
	const int MAX = 100;//Worry about out of memory
	char number[100];
	memset(number,'\0',sizeof(number));
	int digits = 0;
	gets(number);
	for(int i = 0; number[i] != '\0'; i++)
		digits++;
	printf("%d", digits * 2);
	return 0;
}