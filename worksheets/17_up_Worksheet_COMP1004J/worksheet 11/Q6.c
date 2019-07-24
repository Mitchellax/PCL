#include <stdio.h>

#define BITS 1000

int values[BITS];
int readBits = 0;
int max;

short readValues(void)
{
	int i = 0;
	while(~scanf("%d", &values[i]))
	{
		i++;
		readBits++;
	}
	return 1;
}

void printValues(void)
{
	int i;
	for (i = 0; i < readBits; i++)
		printf("%d ", values[i]);
	printf("\n");
	return;
}

void maxValue(void)
{
	int i;
	int temp = values[0];
	for (i = 1; i < readBits; i++)
	{
		if (temp < values[i])
			temp = values[i];
	}
	printf("%d\n", temp);
	return;
}

void minValue(void)
{
	int i;
	int temp = values[0];
	for (i = 1; i < readBits; i++)
	{
		if (temp > values[i])
			temp = values[i];
	}
	printf("%d\n", temp);
	return;
}

void averageValue(void)
{
	int i;
	int temp = values[0];
	for (i = 1; i < readBits; i++)
		temp += values[i];
	printf("%d\n", temp / readBits);
	return;
}


int main(int argc, char const *argv[])
{
	if(readValues())
	{
		printValues();
		maxValue();
		minValue();
		averageValue();
	}
	else
		printf("Something get wrong\n");
	return 0;
}