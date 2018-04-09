#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temp;
    float ave = 0;
    int i = 1;
    for(; i <= 10; i++)
    {
        printf("Please input a number: ");
        scanf("%f",&temp);
        ave = (ave * (i - 1) + temp) / i;
    }
    printf("The average of these numbers approach to %.2f\n",ave);
    getchar();
    return 0;
}
