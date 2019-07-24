#include <stdio.h>

int main(int argc, char const *argv[])
{
	double a = 100;
	int b = 100;
	char c = 'c';
	double * P_a = &a;
	int * P_b = &b;
	char * P_c = &c;
	printf("Values & sizes of vars\n");
	printf("%lf\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(b));
	printf("%d\n", sizeof(c));
	printf("\nValues & sizes of pointers\n");
	printf("%p\n", P_a);
	printf("%p\n", P_b);
	printf("%p\n", P_c);
	printf("%d\n", sizeof(P_a));
	printf("%d\n", sizeof(P_b));
	printf("%d\n", sizeof(P_c));
	printf("\nValues & sizes of pointers` pointers\n");
	printf("%p\n", &P_a);
	printf("%p\n", &P_b);
	printf("%p\n", &P_c);
	printf("%d\n", sizeof(&P_a));
	printf("%d\n", sizeof(&P_b));
	printf("%d\n", sizeof(&P_c));

	return 0;
}