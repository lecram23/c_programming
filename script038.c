#include <stdio.h>
#include <stdlib.h>

struct test1{
	char a;
	char b;
	double c;
};

union test2{
	char a;
	int b;
	double c;
};

int main(void)
{
	printf("Struct benötigt %d Bytes\n", sizeof(struct test1));
	printf("Union benötigt %d Bytes\n", sizeof(union test2));

	return EXIT_SUCCESS;
}
