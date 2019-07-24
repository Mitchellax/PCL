#include <stdio.h>
#include <memory.h>

char modulus(char a, short if_CAP)
{
	if(if_CAP)
	{
		a += -'A';
		a = a % 26;
		a += 'A';
	}
	else
	{
		a += -'a';
		a = a % 26;
		a += 'a';
	}
	return a;
}

int main(int argc, char const *argv[])
{
	const int MAX = 200;
	const int shift = 3;
	char string[MAX];
	int i;
	memset(string, 0, sizeof(string));
	for (i = 0; i < MAX; i++)
	{
		char temp = getchar();
		if(temp != '\n')
			string[i] = temp;
		else
			break;
	}

	for (i = 0; i < MAX; i++)
	{
		if(string[i] >= 'a' && string[i] <= 'z')
			string[i] = modulus(string[i] + shift, 0);
		else if(string[i] >= 'A' && string[i] <= 'Z')
			string[i] = modulus(string[i] + shift, 1);
		else if(string[i] == '\n' || string[i] == 0)
			break;
		else if(string[i] == ' ')
			continue;
		else
			printf("Something get wrong\n");
	}

	for (i = 0; i < MAX; i++)
	{
		if(string[i] != '\n' && string[i] != 0)
			putchar(string[i]);
		else
			break;
	}

	return 0;
}