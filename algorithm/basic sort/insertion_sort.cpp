//=================================================================

// Array edition (General edition)

// Name: insertion_sort
// Function: Sort a series by insertion sort
// I:
//		A array that need to be sorted
//		A integer marked the subscript of where begin
//		A integer marked the subscript of where end
// O: NONE (The original array has been sorted from small to large)
// Include: NONE

template <typename T> void insertion_sort(T num[], int beg, int end);

template <typename T> void insertion_sort(T num[], int beg, int end)
{
	for (int i = beg + 1; i < end; i++)
	{
		T key = num[i];
		int j = i - 1;
		while(j >= 0 && num[j] > key)
		{
			num[j + 1] = num[j];
			j = j - 1;
		}
		num[j + 1] = key;
	}
	return;
}


//===================================================================

//===================================================================

// With gaps edition (For shell sort or other special usage)

// Name: insertion_sort_withgap
// Function: Sort a series by insertion sort (With gaps but all elements)
// I:
//		A array that need to be sorted by gaps
//		A integer marked the subscript of where begin
//		A integer marked the subscript of where end
//		A integer marked the length of gap
// O: NONE (The original array has been sorted from small to large with gaps)
// Include: NONE

template <typename T> void insertion_sort_withgap(T num[], int beg, int end, int gap);


template <typename T> void insertion_sort_withgap(T num[], int beg, int end, int gap)
{
	for (int i = beg + 1; i < end; i += gap)
	{
		T key = num[i];
		int j = i - gap;
		while(j >= 0 && num[j] > key)
		{
			num[j + gap] = num[j];
			j = j - gap;
		}
		num[j + gap] = key;
	}
	return;
}