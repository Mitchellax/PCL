/*Because the function gets() may cause out of memory,and I have been told never use it in C.So I use scanf() instead of it,sorry about it.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[10];
    printf("What is your name?\n");
    scanf("%10s",&name[0]);
    printf("Hi %s, nice to meet you\n",name);
    getchar();
    return 0;
}
