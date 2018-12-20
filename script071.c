#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *quelle;
	int c; 
	char datei[20];
	fpos_t pos;

	printf("Welche Datei wollen Sie oeefnen : ");
	scanf("%s", datei);

	if((quelle=fopen(datei, "r")) == NULL){
		fprintf(stderr, "Konnte %s nicht oeffnen !!\n", datei);
		return EXIT_FAILURE;
	}

//	fseek(quelle, 0L, SEEK_END);
	fgetpos(quelle, &pos);
	printf("Der Positionszeiger zeigt auf Byte : %ld\n", pos);

	
	while((c = getc(quelle)) != EOF)
		putc(c, stdout);

	printf("Groesse der Datei= Byte : %ld ", ftell(quelle));

	// Wir setzten den FILE-Zeiger wieder an den Anfang der Datei
	fseek(quelle, 0L, SEEK_SET);
	//fsetpos(quelle, &pos);
	printf("Wie sind wieder an Position %ld\n", pos);


	return EXIT_SUCCESS;	
}
