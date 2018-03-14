// Name: digits_count
// Function: To count the digits of the inputed number
// I: The number should be counted digits
// O: The number`s digits
// Include: NONE
template <typename T> int digits_count(T n)
{
	if (n < 10)
		return 1;
	else
		return (1 + digits_count(n / 10));
}