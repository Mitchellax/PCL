#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bn,ed,i,sum = 0;
    printf("Enter the first number: ");
    scanf("%d",&bn);
    printf("Enter the second number: ");
    scanf("%d",&ed);
    if(bn > ed)
    {
        i = ed;
         while(i <= bn)
        {
            sum += i;
            i++;
        }
        printf("The sum of the values between %d and %d is %d",bn,ed,sum);
    }
    else if(bn < ed)
    {
        i = bn;
         while(i <= ed)
        {
            sum += i;
            i++;
        }
        printf("The sum of the values between %d and %d is %d",bn,ed,sum);
    }
    else
        printf("There is only one number that %d",bn);
    getchar();
    return 0;
}
