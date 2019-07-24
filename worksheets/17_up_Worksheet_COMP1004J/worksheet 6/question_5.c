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
        printf("The values are equal");
    else
        printf("The values are not equal");
    getchar();
    return 0;
}
