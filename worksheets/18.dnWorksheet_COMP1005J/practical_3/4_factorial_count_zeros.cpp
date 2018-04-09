// Name: factorial_zeros
// Function: To count the number of trailing zeros in factorial
// I: An int
// O: The number of its factorial`s zeros
// Include: NONE
int factorial_zeros(int num)
{
	int factorial = 1, count = 0;	
	for (int i = 1; i <= num; i++)
		factorial *= num;
	while(factorial >= 10)
	{
		if(!(factorial % 10))
			count++;
		factorial /= 10;
	}
	return count;
}