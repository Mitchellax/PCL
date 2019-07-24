#include <stdio.h>

int main(int argc, char const *argv[])
{
	char name[9];
	name[0] = 'M';	
	name[1] = 'i';	
	name[2] = 't';	
	name[3] = 'c';	
	name[4] = 'h';	
	name[5] = 'e';	
	name[6] = 'l';	
	name[7] = 'l';
	name[8] = '\0';	
	printf("%s\n", name);
	
	for (int i = 0; i < 8; i++)
		printf("%c",name[7 - i]);
	printf("\n");		
	
	for (int i = 0; i < 8; i++)
		printf("%d ",(int)name[7 - i]);
	printf("\n");
	return 0;
}