// ------------------------------------------------------------------
// File Name: L1_003.cpp
// Author: Mitchell
// mail: mitchellax2333@outlook.com
// Created Time: 2018/7/3 19:49:37
// =================================================================

#include <iostream>
using namespace std;
class _number
{
    private:
	int digits[10];
	void IniArray(void);
	void DivideNumber(void);
    public:
	int num;
	void GetNumber(void);
	void PrintDigits(void);
};
int main()
{
    std::ios::sync_with_stdio(false);
    _number N;
    N.GetNumber();
    N.PrintDigits();
    return 0;
}
void _number::IniArray(void)
{
    digits[0] = 0;
    digits[1] = 0;
    digits[2] = 0;
    digits[3] = 0;
    digits[4] = 0;
    digits[5] = 0;
    digits[6] = 0;
    digits[7] = 0;
    digits[8] = 0;
    digits[9] = 0;
    return;
}
void _number::DivideNumber(void)
{
    IniArray();
    int number = num;
    while (number >= 10)
    {
	digits[number % 10] = digits[number % 10] + 1;
	number = number / 10;
    }
    digits[number] = digits[number] + 1;
    return;
}

void _number::GetNumber(void)
{cin >> num;}

void _number::PrintDigits(void)
{
    DivideNumber();
    int i = 0;
    while (i != 10)
    {
	if (digits[i] != 0)
	{cout << i << ":" << digits[i] << endl;}
	i = i + 1;
    }
    return;
}
