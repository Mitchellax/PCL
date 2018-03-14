// Normal edition

// Name: trailing_zeros
// Function: To count the number of trailing zeros in an integer
// I: An int
// O: The number of zeros
// Include: NONE
int trailing_zeros(int num)
{
	if(num >= 10)
		return(!(num % 10) + trailing_zeros(num / 10));
	else
		return !num;
}


// One-line edition

// Name: trailing_zeros
// Function: To count the number of trailing zeros in an integer
// I: An int
// O: The number of zeros
// Include: NONE
int trailing_zeros(int num)
{return (num >= 10 ? (!(num % 10) + trailing_zeros(num / 10)) : !num);}