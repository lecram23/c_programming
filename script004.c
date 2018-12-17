#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str1[] = "Hello";
	char str2[] = "Hello";

	int num1[] = {1,2,3,4,5,6};
	int num2[] = {1,3,5,7,9,1};

	int cmp;

	cmp=memcmp( (char *)str1, (char *)str2, sizeof(str1 ));

	if(cmp == 0)
		printf("Both Strings are equal\n");
	else
		printf("Both String are NOT equal\n");
	
	cmp=memcmp( (int *)num1, (int *)num2, sizeof(num1)/sizeof(int) );

	if(cmp==0)
		printf("The content of both arrays are equal");
	else
		printf("The content of both arrays are NOT equal");

	return EXIT_SUCCESS;
}
