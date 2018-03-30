// Name: swap
// Function: Swap two variables` value
// I: Two variables
// O: NONE (two variables` value have been swaped )
// Include: NONE

template <typename T> void swap(T &a, T &b);

template <typename T> void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
	return;
}