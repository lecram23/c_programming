#include <stdio.h>
#include <stdlib.h>

struct speicher{
	char x;
	int z;
}__attribute__((packed));


int main(void)
{
	struct speicher test;

	printf("%u Bytes\n", sizeof(test));
	return EXIT_SUCCESS;
}
