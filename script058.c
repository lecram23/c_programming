#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_MAX 255

int main(void)
{
	FILE *quelle, *ziel;
	int c;
	char name_q[FILE_MAX], name_z[FILE_MAX];

	printf("Name der Quelldatei : ");
	scanf("%s", name_q);
	quelle = fopen(name_q, "rb");

	if(quelle == NULL){
		printf("Konnte %s nicht finden bzw. öffnen!\n", name_q);
		return EXIT_FAILURE;
	}else{
		printf("\nName der Zieldatei : ");
		scanf("%s", name_z);
		ziel = fopen(name_z, "w+b");

		if(ziel == NULL){
			printf("Konnte Zieldatei nicht erzeugen !\n");
			return EXIT_FAILURE;
		}else{
			while(c=getc(quelle) != EOF)
				putc(c,ziel);
		}
	}

	return EXIT_SUCCESS; 
}
