#include <stdio.h>

int main(int argc, char const *argv[])
{
	int ans[10];
	int sum = 0,ave;
	int i,max,min;
	for(i = 0; i <= 9; i++)
	{
		printf("Please input a num\n");
		scanf("%d",&ans[0] + i);
	}
	for (i = 0; i <= 9; i++)
		sum += ans[i];

	ave = sum / 10;
	printf("The average is %d\n",ave);
	for (i = 0; i <= 9; i++)
	{
		if(ans[i] > ave)
			printf("%d is above the average\n", ans[i]);
		else if(ans[i] < ave)
			printf("%d is below the average\n", ans[i]);
	}
	max = ans[0];
	min = ans[0];
	for (i = 1; i <= 9; i++)
	{
		if(ans[i] > max)
			max = ans[i];
		if(ans[i] < min)
			min = ans[i];
	}
	printf("%d is the maximum and %d is the minimum\n", max, min);
    return 0;
}
