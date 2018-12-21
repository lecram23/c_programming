#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATASIZE 1000000L
#define FILE1 "test.txt"
#define FILE2 "test2.txt"

void copy1(char *quelle, char *ziel){
	FILE *q, *z;
	int c;
	time_t t1 = time(NULL);

	printf("Kopiere zeichenweise mit getc() und putc()\n");
	q=fopen(quelle, "rb");

	if(q!= NULL){
		z = fopen(ziel, "wb");
		if(NULL == z){
			fprintf(stderr, "Fehler beim Öffnen (%s)\n", ziel);
			exit(EXIT_FAILURE);
		}
	}else{
		fprintf(stderr, "Fehler beim Öffnen von %s\n", quelle);
		exit(EXIT_FAILURE);
	}

	while((c=getc(q)) != EOF)
		putc(c,z);
	fclose(q);
	fclose(z);

	printf("Zeit = %d sec.\n", time(NULL)-t1);
}

void copy2(char *quelle, char *ziel)
{
	FILE *q, *z;
	static char puffer1[BUFSIZ];
	static char puffer2[BUFSIZ];
	int c;
	time_t t1 = time(NULL);

	printf("Gepuffertes Kopiere mit setbuf(stream, BUFSIZE)\n");
	q=fopen(quelle, "rb");

	if(q!= NULL){
		z = fopen(ziel, "wb");
		if(NULL == z){
			fprintf(stderr, "Fehler beim Oeffnen (%s)\n", ziel);
			exit(EXIT_FAILURE);
		}
	}else{
		fprintf(stderr, "Fehler beim Öffnen von %s\n", quelle);
		exit(EXIT_FAILURE);
	}

	setbuf(q, puffer1);
	setbuf(z, puffer2); 
	
	while((c=getc(q)) != EOF)
		putc(c,z);

	fclose(q);
	fclose(z);
	printf("Zeit = %d sec. \n", time(NULL)-t1);
}

void copy3(char *quelle, char *ziel){
	FILE *q, *z;
	int c;
	time_t t1 = time(NULL);

	printf("Ungepuffertes Kopieren mit setbuf(stream, NULL)\n");
	q = fopen(quelle, "rb");
	if(q != NULL){
		z = fopen(ziel, "wb");
		if(NULL == z){
			fprintf(stderr, "Fehler beim Öffnen (%s)\n", ziel);
			exit(EXIT_FAILURE);
		}
	}else{
		fprintf(stderr, "Fehler beim Öffnen von %s\n", quelle);
		exit(EXIT_FAILURE);
	}

	setbuf(q, NULL); 
	setbuf(z, NULL);

	while((c=getc(q)) != EOF)
		putc(c,z);

	fclose(q);
	fclose(z);
	printf("Zeit = %d sec.\n", time(NULL)-t1);	
}

void erzeuge_datei(void){
	FILE *create = fopen(FILE1, "wb"); 

	if(NULL == create){
		fprintf(stderr, "Konnte keine Datei erzeugen \n");
		exit(EXIT_FAILURE);
	}

	fseek(create, DATASIZE-1, SEEK_SET);
	putc('x', create); 
	fclose(create);
}

int main(void)
{
	printf("Datei %s wird erzeugt\n", FILE1),
	//erzeuge_datei();
	copy1(FILE1, FILE2);
	copy2(FILE1, FILE2),
	copy3(FILE1, FILE2);

	remove(FILE1);
	remove(FILE2);

	return EXIT_SUCCESS;

}
