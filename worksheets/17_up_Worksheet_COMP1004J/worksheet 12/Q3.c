#include <stdio.h>

void bigVowels(char * P_str, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if(*(P_str + i) == 'a' || *(P_str + i) == 'e' || *(P_str + i) == 'i' || *(P_str + i) == 'o' || *(P_str + i) == 'u')
			*(P_str + i) -= 'a' - 'A';
	}
	return;
}
int main(int argc, char const *argv[])
{
	char str[] = "asdasdasd";
	bigVowels(str, sizeof(str));
	printf("%s\n", str);
	return 0;
}