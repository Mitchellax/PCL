// Given 1st January 1900 was a Monday. 
// Writing a program to read in a month and a year since then 
// and print the calendar for that month

// using 'while' make this code ugly, but our college force us to use it.

#include <stdio.h>

bool ifleap(int year)
{
	if(!(year % 4))
	{
		if(!(year % 100))
		{
			if(!(year % 400))
				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;
}

void printclender(int DofW, int AofD)
{
	printf("-------------------------------\n");
	printf("  Sun Mon Tue Wed Thu Fri Sat  \n ");
	int i = 1, d = 1;
	while (i <= DofW)
	{
		printf("    ");
		i = i + 1;
	}
	while (d <= AofD)
	{
		if((DofW + d) % 7 == 1)
			printf(" ");
		printf("%4d", d);
		if((DofW + d) % 7 == 0)
		{
			printf("  ");
			printf("\n");
		}
		d = d + 1;
	}
	if((DofW + d) % 7 != 1)
		printf("\n");
	printf("-------------------------------\n");
}

int main(int argc, char const *argv[])
{
	int d = 1, m, y, i, dit = 1;
	const int if_lp_year[2] = {1, 2};
	const int days[12] = {31, 28 ,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	printf("Please enter the month and year: dd yyyy\b\b\b\b\b\b\b");
	scanf("%d %d", &m, &y);
	if(y >= 1900)
	{
		i = 1900;
		while (i < y)
		{
			dit = dit + if_lp_year[ifleap(i)];
			dit = dit % 7;
			i = i + 1;
		}
		i = 0;
		while (i < m - 1)
		{
			dit = dit + days[i];
			dit = dit % 7;
			i = i + 1;
		}
		dit = dit + d - 1;
		if(ifleap(y) && m > 2)
			dit = dit + 1;
		dit = dit % 7;
	}
	else
	{
		i = 1899;
		while (i > y)
		{
			dit = dit + if_lp_year[ifleap(i)];
			dit = dit % 7;
			i = i - 1;
		}
		i = 11;
		while (i > m - 1)
		{
			dit = dit + days[i];
			dit = dit % 7;
			i = i - 1;
		}
		dit = dit + days[m] - d;
		if(ifleap(y) && m <= 2)
			dit = dit - 1;
		dit = dit % 7;
	}
	if (m == 2 && ifleap(y))
		printclender(dit, days[m - 1] + 1);
	else
		printclender(dit, days[m - 1]);
	return 0;
}