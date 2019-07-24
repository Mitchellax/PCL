#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	int number;
	bool binary[8];//Just for saving space
	printf("Enter a number:");
	scanf("%d",&number);
	for (int i = 0; i < 8; i++)
	{
		binary[7 - i] = number % 2;
		number = (int)(number / 2);
	}
	for (int i = 0; i < 8; i++)
		printf("%d", binary[i]);
	return 0;
}