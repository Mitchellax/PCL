#include <stdio.h>

#define BITS 20

int values[BITS];

short readValues(void)
{
	int i;
	for (i = 0; i < BITS; i++)
		scanf("%d", &values[i]);
	return 1;
}

void printValues(void)
{
	int i;
	for (i = 0; i < BITS; i++)
		printf("%d ", values[i]);
	printf("\n");
	return;
}

void maxValue(void)
{
	int i;
	int temp = values[0];
	for (i = 1; i < BITS; i++)
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
	for (i = 1; i < BITS; i++)
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
	for (i = 1; i < BITS; i++)
		temp += values[i];
	printf("%d\n", temp / BITS);
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
	return 0;
}