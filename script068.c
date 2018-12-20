#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *quelle, *fehler;
	int c;
	char datei[20];
	long pos = 0;

	printf("Welche Datei wollen Sie oeffnen : ");
	scanf("%s", datei);
	
	if((quelle=fopen(datei, "a+")) == NULL){
		if((fehler=fopen("fehler.log","a+")) != NULL){
			fprintf(fehler, "Konnte %s nicht oeffnen\n", datei);
			fprintf(stderr, "Konnte %s nicht oeffnen\n", datei);
			return EXIT_FAILURE;
		}

		fprintf(stderr, "Konnte %s nicht oeffnen\n", datei); 
		return EXIT_FAILURE;
	}

	// Das Zeichen * soll das Ende unserer Eingabe markieren
	printf("Eingabe machen und mit * beenden\n");

	while((c=getc(stdin))!= '*')
		putc(c,quelle);

	// Zeiger 'quelle' an den Anfang der Datei setzen
	fseek(quelle, 0L, SEEK_SET);

	// ganze Datei auf den Bildschirm ausgeben
	printf("\nAusgabe der kompletten Datei : \n");

	while((c=getc(quelle)) != EOF)
		putc(c,stdout);

	// Zur Demonstration gehen wir von der aktuellen Position 
	// 10 Zeichen zurück und geben die letzten 10 Zeichen aus
	printf("\nDie letzten 10 Zeichen : ");
	fseek(quelle, -10L, SEEK_CUR);

	while((c=getc(quelle)) != EOF)
		putc(c,stdout);

	// Selbst feglegen, wie viele Zeichen vom Start eingerückt werden sollen
	printf("Anzahl der Stellen einrücken vom Anfang : ");
	scanf("&ld", &pos);
	fseek(quelle, 0L, SEEK_SET);
	fseek(quelle, pos, SEEK_CUR);

	while((c=getc(quelle)) != EOF)
		putc(c,stdout);

	return EXIT_SUCCESS;
}
