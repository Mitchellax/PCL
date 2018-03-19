#include<cstdio>

const int INFTY = 2147483647;


template <typename T> void merge (T * num, int begSub, int midSub, int endSub)
{
	int preLength = midSub - begSub + 1;
	int bacLength = endSub - midSub;
	T * L = new int [preLength + 1];
	T * R = new int [bacLength + 1];
	int i, j, k;
	for (i = 0; i < preLength; i++)
		L[i] = num[begSub + i];
	for (j = 0; j < bacLength; j++)
		R[j] = num[midSub + j + 1];
	L[preLength] = INFTY;
	R[bacLength] = INFTY;
	for (i = 0, j = 0, k = begSub; k <= endSub; k++)
	{
		if (L[i] <= R[j])
		{
			num[k] = L[i];
			i++;
		}
		else
		{
			num[k] = R[j];
			j++;
		}
	}
	delete [] L;
	delete [] R;
}


// Name: merge_sort
// Function: Sort a array by merge sort
// I: 
//		a pointer aim to the array which need be sorted
//		a integer mark begin
//		a integer mark end
// O: a series are sorted(smaller to biger)
// Include: NONE

template <typename T> void mergeSort (T * num, int begSub, int endSub)
{
	if (begSub < endSub)
	{
		int midSub = (begSub + endSub) / 2;
		mergeSort <T> (num, begSub, midSub);
		mergeSort <T> (num, midSub + 1, endSub);
		merge <T> (num, begSub, midSub, endSub);
	}
}

int main (int argc, char const * argv[])
{
	int num[8]={8, 7, 8, 9, 4, 3, 11, 19};
	mergeSort <int> (num, 0, 7);
	for (int i = 0;i < 8;++i)
		printf ("%d  ", num[i]);
	return 0;
}