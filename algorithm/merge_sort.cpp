//Array edition  


//!!!!!!!!!!!!!!!!(Can not work now)!!!!!!!!!!!!!!!!!!



// Name: merge
// Function: merge the array smaller
// I: 
//		a array
//		a integer mark begin
//		a integer mark mid
//		a integer mark end
//
//		need a global constant mark date`s limit like const int INFTY = 2147483647 if date is stored by int
// O: two series halved
// Include: NONE

const int INFTY = 2147483647;


template <typename T> void merge(T originArr[], T tempArr[], int begSub, int midSub, int endSub)
{
	int length_1 = midSub - begSub + 1;
	int length_2 = endSub - midSub;
	T array_1[length_1 + 1];
	T array_2[length_2 + 1];
	for (int i = 0; i < length_1; i++)
		array_1[i] = originArr[begSub + i];
	for (int i = 0; i < length_2; i++)
		array_2[i] = originArr[midSub + i + 1];
	array_1[length_1] = INFTY;
	array_2[length_2] = INFTY;
	int i = 0, j = 0;
	for (int k = 0; k <= endSub - begSub + 1; k++)
	{
		if (array_1[i] <= array_2[j])
		{
			tempArr[k] = array_1[i];
			i++;
		}
		else
		{
			tempArr[k] = array_2[j];
			j++;
		}
	}
}

// Name: merge_sort
// Function: Sort a series by merge sort
// I: 
//		a array T num[]
//		a integer mark where begin
//		a integer mark where end
// O: a series are sorted(smaller to biger)
// Include: NONE

template <typename T> void merge_sort(T originArr[], T tempArr[], int begSub, int endSub)
{
    int midSub;
    if(begSub < endSub)
    {
        midSub = (begSub + endSub) / 2;
        merge_sort(originArr, tempArr, begSub, midSub);
        merge_sort(originArr, tempArr, midSub + 1, endSub);
        merge<T>(originArr, tempArr, begSub, midSub, endSub);
    }
}
