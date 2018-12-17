#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a = 10;
	char *string = "void-pointer";
	void *ptr;

	// void-pointer is pointing to variable a
	ptr = (int *)&a;
	printf("ptr = %p a=%p\n", ptr, &a);

	// void pointer pointing to string
	ptr = (char*)string;
	printf("ptr=%p string=%p\n", ptr, string);

	return EXIT_SUCCESS;
}
