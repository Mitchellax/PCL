/*因为按照原题的要求，首字母相同时会导致无输出或错误输出
 *所以我额外实现了在出现相同字母并需要继续比较时，逐位比较，直到得出结果
 */

#include <stdio.h>
#include <memory.h>
#include <string.h>

void get_char(char * str, int size)//For safty and saving memory
{
	int i;
	char temp[200];
	memset(temp, '\0', sizeof(temp));
	gets(temp);
	for (i = 0; i < size - 1; ++i)
		str[i] = temp[i];
}

int main(int argc, char const *argv[])
{
	const int MAX = 10;
	int max_dit, i;
	char fst[MAX];
	char scd[MAX];
	char trd[MAX];
	memset(fst, '\0', sizeof(fst));
	memset(scd, '\0', sizeof(scd));
	memset(trd, '\0', sizeof(trd));
	printf("Enter the first word: ");
	get_char(fst,MAX);
	printf("Enter the second word: ");
	get_char(scd,MAX);
	printf("Enter the third word: ");
	get_char(trd,MAX);
	for (i = 0; i < MAX; ++i)
	{
		int t_1_2 = strcmp(&fst[i],&scd[i]);
		int t_1_3 = strcmp(&fst[i],&trd[i]);
		int t_2_3 = strcmp(&scd[i],&trd[i]);
		short if_rep = 0;
		if(!t_1_2 || !t_1_3 || !t_2_3)
			if_rep = 1;
		if(t_1_2 < 0 && !if_rep)
		{
			if(t_1_3 > 0)
				max_dit = 3;
			else
				max_dit = 1;
			break;
		}
		else if(t_1_2 > 0 && !if_rep)
		{
			if (t_2_3 > 0)
				max_dit = 3;
			else
				max_dit = 2;
			break;
		}
		else if(if_rep)
			continue;
	}
	switch(max_dit)
	{
		case 1:
			printf("<%s>\n", fst);
			break;
		case 2:
			printf("<%s>\n", scd);
			break;
		case 3:
			printf("<%s>\n", trd);
			break;
	}
	return 0;
}