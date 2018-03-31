//======================================================================

// array edition

// Name: swap
// Function: Swap two variables` value
// I: Two variables
// O: NONE (two variables` value have been swaped )
// Include: NONE

template <typename T> void swap(T &a, T &b);

// Name: partition
// Function: part the inputed array into two part hold the elements in first part are smaller than the second.
// I: A array need to be parted
// 		A integer marked the subscript of where begin
// 		A integer marked the subscript of where end
//		A integer marked the subscript of where is standard for partition
// O: The edge of two parts (and the array have parted)
// Include: NONE

// WORNING!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// This function must be predeclared or input all the parameters

template <typename T> int partition(T num[], int beg, int end, int jud = -1);


//---------------------------------------------------------------------

template <typename T> void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
	return;
}

template <typename T> int partition(T num[], int beg, int end, int jud)
{
	if (jud == -1)
		jud = end;
	swap <T> (num[jud], num[end]);
	int temp = num[end];
	int i = beg - 1;
	for (int j = beg; j < end; j++)
	{
		if (num[j] <= temp)
		{
			i++;
			swap <T> (num[i], num[j]);
		}
	}
	swap <T> (num[i + 1], num[end]);
	return i + 1;
}
//========================================================================