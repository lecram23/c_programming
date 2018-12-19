#include <stdio.h>
#include <stdlib.h>

struct speicher{
	char x;
	char z;
};

int main(void)
{
	struct speicher test;

	printf("%u Bytes\n", sizeof(test));
	return EXIT_SUCCESS; 
}
