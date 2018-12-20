#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *datei;
	char filename[20];
	int data;

	printf("Please enter the file you want to open : ");
	scanf("%s", filename);

	datei = fopen(filename, "r");

	if(datei == NULL){
		printf("Unable to read file. Maybe it doesn't exists");
		return EXIT_FAILURE;
	}

	while((data = getc(datei)) != EOF)
		putc(data, stdout);

	fseek(datei, 0L, SEEK_END);
	printf("Your textfile has a size of %ld Bytes\n", ftell(datei));

	return EXIT_SUCCESS;

	
}
