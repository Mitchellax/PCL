/*
1st january 1900 was a monday.
Write a program to read in a 
date since then (d,m,y) and print out what day of the week it is.
*/

#include <iostream>
#include <string>
using namespace std;
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
	int d, m, y, dit = 1;
	const int if_lp_year[2] = {1, 2};
	const int days[12] = {31, 28 ,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	const string week[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	cin >> d;
	cin >> m;
	cin >> y;
	if(y >= 1900)
	{
		for (int i = 1900; i < y; ++i)
		{
			dit += if_lp_year[ifleap(i)];
			dit %= 7;
		}
		for (int i = 0; i < m - 1; ++i)
		{
			dit += days[i];
			dit %= 7;
		}
		dit += d - 1;
		if(ifleap(y) && m > 2)
			dit++;
		dit %= 7;
	}
	else
	{
		for (int i = 1899; i > y; i--)
		{
			dit += if_lp_year[ifleap(i)];
			dit %= 7;
		}
		for (int i = 11; i > m - 1; i--)
		{
			dit += days[i];
			dit %= 7;
		}
		dit += days[m] - d;
		if(ifleap(y) && m <= 2)
			dit--;
		dit %= 7;
	}
	cout << week[--dit] << endl;
	return 0;
}