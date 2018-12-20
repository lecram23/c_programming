#include <stdio.h>
#include <stdlib.h>

#define DATEI "test.txt"

int main(void)
{
	FILE *fp;
	int c;

	fp = fopen(DATEI, "r");

	if(fp == NULL){
		fprintf(stderr, "Konnte %s nicht öffnen\n", DATEI);
		return EXIT_FAILURE;
	}

	while(1){
		while((c=fgetc(fp))){
			if(c == EOF)
				ungetc(c,fp);
			else
				fputc(c,stdout);
		}
	}

	fclose(fp);

	return EXIT_SUCCESS;
}
