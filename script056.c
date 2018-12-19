#include <stdio.h>
#include <stdlib.h>

// this program is reading a file on my computer

int main(void)
{
	char filename[] = "test.txt";
	char operation[] = "r";
	FILE *file;

	file = fopen(filename, operation);

	if(file != NULL){
		printf("File has been successfully opened\n");
		// Writing file to terminal
		char c;
		while( (c = fgetc(file)) != EOF)
			putchar(c);	
	
		return EXIT_SUCCESS;
	}else{
		printf("File could not be loaded\n");
		return EXIT_FAILURE;
	}	
}
