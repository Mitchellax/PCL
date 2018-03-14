// name: digits_divide
// Function: To divide the digits of the inputed number in the output string
// I: The number should be divided digits
// O: A string include number`s digits
// Include: <string>
// 			<iostream>
template <typename T> std::string digits_divide(T n)
{
	if (n < 10)
		return n + '0';
	else
		return ('n % 10' + digits_count(n / 10));
}