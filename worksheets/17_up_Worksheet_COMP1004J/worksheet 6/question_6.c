#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1,a2;
    printf("Enter the first number: ");
    scanf("%d",&a1);
    printf("Enter the second number: ");
    scanf("%d",&a2);
    if(a1 == a2)
        printf("The values are equal and the value is %d",a1);
    else if(a1 > a2)
        printf("The biggest value is %d",a1);
    else if(a1 < a2)
        printf("The biggest number is %d",a2);
    getchar();
    return 0;
}
