#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

bool if_num(char * ch);
short ch_to_num(char * ch);

int main(int argc, char const *argv[])
{
	const int MAX = 100;//scared about out of memory

	char temp[MAX];
	short number[MAX];
	bool if_num_begin = 0;
	bool if_negative = 0;
	bool if_shift[MAX + 1];
	memset(temp,'\0',sizeof(temp));
	memset(if_shift,0,sizeof(if_shift));
	gets(&temp[0]);
	int i_t = 0;
	
	for (int i = 0; i < MAX - 1; i++)
	{
		if(!if_num_begin)
		{
			if(temp[i] == '-')
				if_negative = 1;
		}
		if(if_num(&temp[0] + i))
		{
			if_num_begin = 1;
			number[i_t] = ch_to_num(&temp[0] + i);
			i_t++;
		}
	}
	
	if((number[1] * 2 > 9 && number[0] * 2 + 1 > 9) || (number[1] * 2 < 9 && number[0] * 2 > 9))
	{
		for (int i = 0; i <= i_t; i++)
			number[i_t - i + 1] = number[i_t - i];
		number[0] = 0;
	
		for (int i = 0; i <= i_t; i++)
		{
			if(if_shift[i_t - i + 1])
				number[i_t - i] = number[i_t - i] * 2 + 1;
			else
				number[i_t - i] = number[i_t - i] * 2;
			/*if(number[i_t - i + 1] > 19)//for test
				printf("%d\n", i);					*/
			if(number[i_t - i - 1] > 9)
			{
				number[i_t - i - 1] = number[i_t - i - 1] - 10;
				if_shift[i_t - i - 1] = 1;
			}
		}
		for (int i = 0; i <= i_t; i++)
			printf("%d", number[i]);
	}
	
	else
	{
		for (int i = 0; i <= i_t; i++)
		{
			if(if_shift[i_t - i + 1])
				number[i_t - i] = number[i_t - i] * 2 + 1;
			else
				number[i_t - i] = number[i_t - i] * 2;
			if(number[i_t - i] > 9)
			{
				number[i_t - i] = number[i_t - i] - 10;
				if_shift[i_t - i] = 1;
			}
		}
		if (if_negative)
			printf("-");
	
		for (int i = 0; i < i_t; i++)
			printf("%d", number[i]);
	}	
}

bool if_num(char * ch)
{
	return(*ch >= '0' && *ch <= '9');
}

short ch_to_num(char * ch)
{
	switch(*ch)
	{
		case '0':
		return 0;
		case '1':
		return 1;
		case '2':
		return 2;
		case '3':
		return 3;
		case '4':
		return 4;
		case '5':
		return 5;
		case '6':
		return 6;
		case '7':
		return 7;
		case '8':
		return 8;
		case '9':
		return 9;
	}
}