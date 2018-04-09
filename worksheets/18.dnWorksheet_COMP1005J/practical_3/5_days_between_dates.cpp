#include <cstdio>

int d1, m1, y1, d2, m2, y2;

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
void swap(void)
{
	d1 = d1 ^ d2;
	d2 = d1 ^ d2;
	d1 = d1 ^ d2;
	m1 = m1 ^ m2;
	m2 = m1 ^ m2;
	m1 = m1 ^ m2;
	y1 = y1 ^ y2;
	y2 = y1 ^ y2;
	y1 = y1 ^ y2;
}

int main(int argc, char const *argv[])
{
	const int month[12] = {31, 28 ,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int days = 0, leapyears = 0;
	scanf("%d%d%d", &d1, &m1, &y1);
	scanf("%d%d%d", &d2, &m2, &y2);
	// Input
	if(y1 > y2)
		swap();
	else if(y1 == y2)
	{
		if(m1 > m2)
			swap();
			else if(m1 == m2)
			{
				if(d1 > d2)
					swap();
			}
	}
	// Make date1 < date2
	for (int i = y1; i < y2; i++)
	{
		leapyears += ifleap(i);
		days += 365;
	}
	for (int i = m1; i < m2; i++)
		days += month[i - 1];
	days += d2 - d1;
	printf("%d", days);
	return 0;
}