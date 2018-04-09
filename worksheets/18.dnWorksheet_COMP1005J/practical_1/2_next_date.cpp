#include <cstdio>

int y, m, d;

bool nextday(int monmax)
{
	if(d == monmax)
		{
			m++;
			d = 1;
			return 1;
		}
		else
			d++;
		return 0;
}

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
	scanf("%d %d %d", &d, &m, &y);
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10)
		nextday(31);
	else if(m != 12 && m != 2)
		nextday(30);
	else if(m == 2)
	{
		if(ifleap(y))
			nextday(29);
		else
			nextday(28);
	}
	else if(m == 12)
	{
		if(nextday(31))
			y++;
	}
	printf("%02d %02d %04d", d, m, y);
	return 0;
}