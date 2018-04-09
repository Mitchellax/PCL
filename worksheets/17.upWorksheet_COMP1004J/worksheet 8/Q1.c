#include <stdio.h>
#include <string.h>
#include <memory.h>

int main(int argc, char const *argv[])
{
	const int MAX = 50;
	int letters = 0, vowels = 0,uppercase = 0,lowpercase = 0, digits = 0, i;
	char test[MAX + 1];
	memset(test,0,sizeof(test));
	printf("Please enter some text: ");
	for (i = 0; i < MAX; i++)
	{
		char temp;
		temp = getchar();
		if(temp != '\n')
		{
			test[i] = temp;
			if (test[i] >= 'A' && test[i] <= 'Z')
			{
				letters++;
				uppercase++;
			}
			else if (test[i] >= 'a' && test[i] <= 'z')
			{
				letters++;
				if (test[i] == 'a' || test[i] == 'e' || test[i] == 'i' || test[i] == 'o' || test[i] == 'u')
					vowels++;
				lowpercase++;
			}
			else if (test[i] >= '0' && test[i] <= '9')
				digits++;
		}
		else
			break;
	}
	printf("The text contained %d characters\n", strlen(test));
	printf("%d of the characters are letters\n", letters);
	printf("%d of the characters are uppercase letters\n", uppercase);
	printf("%d of the characters are lowpercase letters\n", lowpercase);
	printf("There are %d vowels\n", vowels);
	printf("There are %d consonants\n", letters - vowels);
	printf("There are %d digits\n", digits);
	return 0;
}