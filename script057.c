#include <stdio.h>
#include <stdlib.h>

#define FILE_MAX 255

void read_char(FILE*);

void read_char(FILE *stream){
	int c;

	while( (c = fgetc(stream)) != EOF )
		putchar(c);
}


int main(int argc, char **argv)
{
	FILE *datei;
	char filename[FILE_MAX];

	if(argc < 2){
		printf("Welche Datei wollen Sie öffnen : ");
		scanf("%s", filename);
		datei = fopen(filename, "r");

		if(datei != NULL)
			read_char(datei);
		else{
			printf("Fehler beim Öffnen von %s\n", filename);
			return EXIT_FAILURE;
		}
	}else{
		datei = fopen(argv[1], "r");

		if(datei != NULL)
			read_char(datei);
		else{
			printf("Konnte %s nicht öffnen!\n", argv[1]);
			return EXIT_FAILURE;
		}
	}


	return EXIT_SUCCESS;
}

