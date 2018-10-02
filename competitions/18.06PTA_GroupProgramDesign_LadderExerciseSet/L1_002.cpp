// ------------------------------------------------------------------
// File Name: L1_002.cpp
// Author: Mitchell
// mail: mitchellax2333@outlook.com
// Created Time: 2018/6/27 20:32:40
// =================================================================

#include <iostream>
using namespace std;

class sandglass
{
    private:
	int lines;
	int numLeft;
	void calLines(void);  
    public:
	char ch;
	int numAll;
	void getNum (void);  
	void getChar (void);
	void print (void);
};

int main()
{
	std::ios::sync_with_stdio(false);
	sandglass SG;
	SG.getNum();
	SG.getChar();
	SG.print();
	return 0;
}
void sandglass::calLines(void)
{
    if (numAll == 0)
    {numLeft = 0;}
    else
    {
	if (numAll == 1)
	{
	    lines = 1;
	    numLeft = 0;
	    return;
	}
        int i = 1;
        while (2 * i * i - 1 <= numAll)
        {i = i + 1;}
        lines = i - 1;
        numLeft = numAll - 2 * lines * lines + 1;
    }
    return;
}

void sandglass::getNum (void)
{cin >> numAll;}

void sandglass::getChar (void)
{cin >> ch;}

void sandglass::print (void)
{
    calLines ();
    int i = lines;
    if (lines == 1)
    {
        cout << ch << endl;
        cout << numLeft;
	return;
    }
    while (i != 0)
    {
        int j = lines - i;
        int k = 2 * i - 1;
        while (j != 0)
        {
    	cout << " ";
    	j = j - 1;
        }
        while (k != 0)
        {
    	cout << ch;
    	k = k - 1;
        }
        cout << endl;
        i = i - 1;
    }
    i = 2;
    while (i != lines + 1)
    {
        int j = lines - i;
        int k = 2 * i - 1;
        while (j != 0)
        {
    	cout << " ";
    	j = j - 1;
        }
        while (k != 0)
        {
    	cout << ch;
    	k = k - 1;
        }
        cout << endl;
        i = i + 1;
    }
    cout << numLeft;
}
