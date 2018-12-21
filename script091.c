#include <stdio.h>
#include <stdlib.h>

void my_remove(char *rm){
	unsigned long size;

	FILE *rem = fopen(rm, "w+b");

	if(rem != NULL){
		fseek(rem, 0L, SEEK_END);
		size=ftell(rem); 
		fwrite((char *)'\0',1,size,rem);
		fclose(rem);
		remove(rm);
	}
}

int main(void)
{
	char datei[] = "test.txt";
	my_remove(datei);
	return EXIT_SUCCESS;
}
