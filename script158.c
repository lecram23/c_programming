#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cytpe.h>

// Prototypen
void bigfont(char *, char*);
void smallfont(char *, char*);
void international(char *, char*);
void open_file(char *, char*, FILE**, FILE**);

void bigfont(char *arg2, char *arg3){
	FILE *in, *out;
	int c;

	open_file(arg2, arg3, &in, &out);

	while((c=getc(in)) != EOF){
		if(islower(c))
			putc(toupper(c), out);
		else
			putc(c,out);
	}
}

void smallfont(char *arg2, char *arg3){
	FILE *in, *out;
	int c;

	open_file(arg2, arg3, &in, &out);
	while((c=getc(in)) != EOF){
		if(isupper(c))
			putc(tolower(c),out);
		else
			putc(c,out);
	}
}

void international(char *arg2, char *arg3){
	FILE *in, *out;
	int c;

	open_file(arg2, arg3, &in,&out); 
	while((c=getc(in)) != EOF){
		if(isascii(c) == 0)
			putc(toascii(c), out);
		else
			putc(c,out);
	}
}

void open_file(char *quelle, char *ziel, FILE **input, FILE **output){
	if((*input=fopen(quelle, "r+")) == NULL){
		printf("Fehler beim Oeffnen (Lesen) von %s\n", quelle);
		exit(EXIT_FAILURE);
	}
	if((*output=fopen(ziel, "w+")) == NULL){
		printf("Fehler beim Oeffnen ( Schreiben) von %s\n", ziel);
		exit(EXIT_FAILURE); 
	}
}

int main(int argc, char*argv[]){
	if(argc<4){
		printf("Verwendung: "
		"Programme - [Schalter] datei.txt Zieldatei.txt\n"
		"für -[Schalter] : -b (komplette Textdatei in Grossschrift)\n"
		"	           -s (komplette Textdatei in Kleinschrift)\n"
		"		   -i (nationale Zeichen zu ASCII-Zeichen\)\n");
		return EXIT_FAILURE;
	}

	if(strcmp(argv[1], "-b")==0)
		bigfont(argv[2], argv[3]);
	else if(strcmp(argv[1], "-s")==0)
		smallfont(argv[2], argv[3]);
	else if(strcmp(argv[1], "-i")==0)
		international(argv[2], argv[3]);
	else{
		printf("Verwendung: "
		"Programme -[Schalter] datei.txt Zieldatei.txt\n"
		"für -[Schalter] : -b (komplette Textdatei in Grossschrift)\n"
		"    		   -s (komplette Textdatei in Kleinschrift)\n"
		"		   -i (nationale Zeichen zu ASCII-Zeichen)\n");

		return EXIT_SUCCESS;
	}

	return EXIT_SUCCESS; 
}














