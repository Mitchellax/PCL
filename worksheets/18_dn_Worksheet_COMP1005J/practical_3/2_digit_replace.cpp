// Name: int_replace
// Function: Input an integer and replace the digit x by the digit y in the integer number.
// I: An int
// O: An int already be replaced
// Include: NONE

int replace(int x, int y,int n)
{return (n < 10?(n == x ? y : n) : (n % 10 == x ? y : n % 10) + replace(x, y, n / 10) * 10);}
