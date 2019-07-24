//输出要求输出每位，我理解的是百位、十位、个位
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int number;
	int digits = 0;
	int i,k = 0;
	char digit[4] = {'0', '0', '0', '\0'};
	re_enter: printf("Your input is unture\n");
	printf("Please enter a number between 0 and 1000 (exclusive)\n");
	scanf("%d",&number);
	if (number < 0 || number > 999)
		goto re_enter;
	if (!number)
		digits++;
	for (i = 0; i <= 3; ++i)
	{
		if (number)
		{
			digits++;
			k++;
		}
		else
			break;
		digit[3 - k] = (char)(number % 10 + '0');
		number = number / 10;
	}
	printf("%d\n", digits);
	for (i = 0; i < 3; ++i)
		putchar(digit[i]);
	return 0;
}