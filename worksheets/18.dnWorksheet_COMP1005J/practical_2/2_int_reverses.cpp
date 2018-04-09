/*
write a function that takes an integer and reverses it.
*/

// Name: int_reverses
// Function: Input an integer and reverses it to output
// I: An int
// O: The number`s reversal number
// Include: NONE
int reverse (int num,int s = 0)
{
	s = 10 * s + num % 10;
	if (num > 10) 
		reverse (num / 10, s);
	else return s;
}


// With template edition
// Name: int_reverses
// Function: Input an integer and reverses it to output
// I: An integer
// O: The number`s reversal number
// Include: NONE
template <typename T> T reverse (T num, T s = 0)
{
	s = 10 * s + num % 10;
	if (num > 10) 
		reverse (num / 10, s);
	else return s;
}