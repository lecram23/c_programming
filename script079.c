#include <stdio.h>
#include <stdlib.h>

#define BUF 255

char temp[BUF];
char puffer[BUF];

// Auslesen der n-ten zeile

char *getsline_number(int n, FILE *file){
	int i;

	for(i=0;i<n-1;i++){
		if(fgets(temp, BUF, file) == NULL)
			return NULL;
		if(fgets(puffer, BUF, file) == NULL)
			return NULL;
		return puffer;
	}
}

int main(int argc, char*argv[]){
	FILE *f;
	unsigned int line;
	char *linenr;

	if(argc < 2){
		fprintf(stderr, "Verwendung : %s datei\n", *argv);
		return EXIT_FAILURE;
	}

	f = fopen(argv[1], "r");

	if(f==NULL){
		printf("Fehler beim Öffnen");
		return EXIT_FAILURE;
	}

	printf("Welche Zeile wollen Sie lesen : ");
	scanf("%s", &line);

	linenr=getsline_number(line,f);

	if(linenr == null){
		fprintf(stderr, "Fehler beim Lesen der %d-ten Zeile??\n", line);
		return EXIT_FAILURE;
	}

	printf("Zeile %d : %s\n", line, linenr); 
	return EXIT_SUCCESS;
}
