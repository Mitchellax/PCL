#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int aim = rand() % 200;
    int guess = -1;
    printf("Please guess the aim number\n");
   // printf("%d\n",aim);
    while(aim != guess)
    {
        scanf("%d",&guess);
        if(aim < guess)
            printf("\nIt is bigger,try again\n");
        else if(aim > guess)
            printf("It is smaller,try again\n");
    }
    printf("Right!!!");
    return 0;
}

