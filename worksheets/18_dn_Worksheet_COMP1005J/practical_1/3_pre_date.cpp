#include <cstdio>

int d, m, y;

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

bool predate(int monmax)
{
	if(d == 1)
	{
		m--;
		d = monmax;
		return 1;
	}
	else
		d--;
	return 0;
}

int main(int argc, char const *argv[])
{
	scanf("%d %d %d", &d, &m, &y);
	if(m == 2 || m == 4 || m == 6 || m == 8 || m == 9 || m == 11)
		predate(31);
	else if(m != 1 && m != 3)
		predate(30);
	else if(m == 3)
	{
		if(ifleap(y))
			predate(29);
		else
			predate(28);
	}
	else if(m == 1)
	{
		if(predate(31))
			y--;
		m = 12;
	}
	printf("%02d %02d %04d", d, m, y);
	return 0;
}

