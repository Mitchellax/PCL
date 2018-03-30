//=================================================================

//Global variable edition

// Name: insertion_sort
// Function: Sort a series by insertion sort
// I:
//		A global array T num[]
//		A integer mark where begin int beg
//		A integer mark where end int end
// O: A series are sorted(smaller to biger)
// Include: NONE

template <typename T> void insertion_sort(int beg, int end);

template <typename T> void insertion_sort(int beg, int end)
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