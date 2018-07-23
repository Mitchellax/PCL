// ------------------------------------------------------------------
// File Name: 1000.cpp
// Author: Mitchell
// mail: mitchellax2333@outlook.com
// Created Time: 2018/5/13 0:10:42
// =================================================================

#include <iostream>
using namespace std;

void GetNumsIn(int &num1, int &num2);
void PlusAndPrint(int &num1, int &num2);

int main()
{
	std::ios::sync_with_stdio(false);
	int A, B;
	GetNumsIn(A, B);
	PlusAndPrint(A, B);
	return 0;
}

inline void GetNumsIn(int &num1, int &num2)
{
	cin >> num1;
	cin >> num2;
	return ;
}

inline void PlusAndPrint(int &num1, int &num2)
{
	cout << num1 + num2;
	return ;
}
