#include <stdio.h>
#include <stdlib.h>

int main()
{
    float height,base;
    printf("Enter base: \n");
    scanf("%f",&base);
    printf("Enter height: \n");
    scanf("%f",&height);
    printf("The area of triangle with base %.1f and height %.1f is %.1f\n",base,height,base * height /2);
    getchar();
    return 0;
}
