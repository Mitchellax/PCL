#include <cstdio>
#include <cmath>
int main(int argc, char const *argv[])
{
  
    int num, chk = 0;
    scanf("%d", &num);
    if(num == 1 || num == 2)
      printf("Yes\n");
    int temp = sqrt(num) + 1;
    for (int j = 2; j <= temp; j++)
      chk += !(num % j);
    if(chk)
      printf("No\n");
    else
      printf("Yes\n");
  return 0;
}
