#include<cstdio>

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


int main (int argc, char const * argv[])
{
	int num[30] = {8, 7, 8, 9, 4, 3, 11, 19, 655, 123, 12, 321, 53, 232, 1, 3, 321, 66, 6, 23, 213, 5, 3, 213, 67, 75, 45, 6, 980, 2222};
	shell_sort <int> (num, 0, 29);
	for (int i = 0;i < 30;++i)
		printf ("%d  ", num[i]);
	return 0;
}

