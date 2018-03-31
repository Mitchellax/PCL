//=================================================================

// Array edition (General edition)

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

// Name: shell_sort
// Function: Sort a series by shell sort (calling insertion_sort of a loop)
// I:
//		A array that need to be sorted
//		A integer marked the subscript of where begin
//		A integer marked the subscript of where end
// O: NONE (The original array has been sorted from small to large)
// Include: NONE

template <typename T> void shell_sort(T num[], int beg, int end);


//----------------------------------------------------------------




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

template <typename T> void shell_sort(T num[], int beg, int end)
{
	int length = end - beg + 1, j = 2, k = 4;
	int G[2] = {1, 4};
	while (length > (k * 3 + 1))
	{
		int * G = new int [++j];
		k = k * 3 + 1;
		G[j--] = k;
	}
	for (int i = j - 1; i >= 0; i--)
		insertion_sort_withgap <T> (num, beg, end, G[i]);
}

//===================================================================