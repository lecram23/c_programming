#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char alt[20], neu[20];

	printf("Which file you want to rename : ");
	scanf("%s", alt);

	printf("What's the name of the new file : ");
	scanf("%s", neu); 

	if((rename(alt,neu)) < 0){
		fprintf(stderr, "Error while renaming file from %s", alt); 
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
