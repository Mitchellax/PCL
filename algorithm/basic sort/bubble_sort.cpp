//==============================================================

// Array edition (General edition)

// Name: swap
// Function: Swap two variables` value
// I: Two variables
// O: NONE (two variables` value have been swaped )
// Include: NONE

template <typename T> void swap(T &a, T &b);

// Name: bubble_sort
// Function: Sort a series by bubble sort
// I: 
//		A array that need to be sorted
//		A integer marked the subscript of where begin
//		A integer marked the subscript of where end
// O: NONE (The original array has been sorted from small to large)
// Include: NONE

template <typename T> void bubble_sort(T num[], int beg, int end);

//--------------------------------------------------------------

template <typename T> void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
	return;
}

template <typename T> void bubble_sort(T num[], int beg, int end)
{
	int flag = 1;
	while(flag)
	{
		flag = 0;
		for (int i = end; i >= beg ; i--)
		{
			if(num[i] < num[i - 1])
			{
				swap <T> (num[i], num[i - 1]);
				flag = 1;
			}
		}
	}
}

//==============================================================