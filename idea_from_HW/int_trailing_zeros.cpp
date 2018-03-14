// Normal edition

// Name: trailing_zeros
// Function: To count the number of trailing zeros in an integer
// I: An int
// O: The number of zeros
// Include: NONE
template <typename T> T trailing_zeros(T num)
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
template <typename T> T trailing_zeros(T num)
{return (num >= 10 ? (!(num % 10) + trailing_zeros(num / 10)) : !num);}