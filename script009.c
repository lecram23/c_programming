#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n=3;
	int array[5] = {4,2,3,4,5};
	int *ptr = array;

	printf("%d", *ptr);
	printf("%d", ptr[0]);
	printf("%d", *array);
	printf("%d", array[0]);
	printf("\n");

	printf("%d", *(ptr+3));
	printf("%d", ptr[3]);
	printf("%d", *(array+3));
	printf("%d", array[3]);
	printf("\n");

	printf("%p", ptr);
	printf("%p", &ptr[0]);
	printf("%p", array);
	printf("%p", &array[0]);
	printf("\n");

	printf("%p", ptr+3);
	printf("%p", ptr[3]);
	printf("%p", (array+3));
	printf("%p", &array[3]);

	return EXIT_SUCCESS;
}
