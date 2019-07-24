#include <cstdio>

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

int main(int argc, char const *argv[])
{
	int y;
	scanf("%d", &y);
	if(ifleap(y))
		printf("%d is a leap year", y);
	else
		printf("%d is not a leap year", y);
	return 0;
}

