#include <stdio.h>
#include <stdlib.h>

#define BUF 255

char temp[BUF];
char puffer[BUF];
int i;

char *getsline_number(int n1, int n2, FILE *file){
	for(i=0;i<n1-1;i++){
		if(fgets(temp, BUF, file) == NULL)
			return NULL;
		printf("\n");
		for(i=n1;i<=n2;i++){
			if(fgets(puffer, BUF,file)== NULL)
				return NULL;

		printf("Zeile %d: %s", i , puffer);
		}	
	}
}

int main(int argc, char *argv[]){
	FILE *f;
	int line1, line2;
	char *linenr;

	if(argc < 2){
		fprintf(stderr, "Verwendung : %s datei\n", *argv);
		return EXIT_FAILURE;
	}

	f = fopen(argv[1], "r");

	if(f== NULL){
		printf("Fehler bei fopen()...\n");
		return EXIT_FAILURE;
	}

	printf("Von Zeile wollen sie lesen : ."); 
	scanf("%d", &line1);
	printf("Bis zeile wollen Sie lesen : ");
	scanf("%d", &line2);

	if(line2 < line1){
		fprintf(stderr, "Bis-Zeile kann nicht groesser sein als von Zeile!\n");
		return EXIT_FAILURE;
	}

	linenr=getsline_number(line1, line2,f);

	if(linenr == NULL){
		fprintf(stderr, "Fehler biem Lesen der %d-ten Zeile??\n", i);
		return EXIT_FAILURE;
	}

	printf("\n");
	return EXIT_SUCCESS;
}
