#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct address{
	char vname[MAX];
	char nname[MAX];
	long PLZ;
	char ort[MAX];
	int geburtsjahr;
};


void ausgabe(struct address x)
{
	printf("\n\nSie gaben ein : \n\n");
	printf("Vorname..........%s\n", x.vname);
	printf("Nachname.........%s\n", x.nname); 
	printf("PLZ..............%ld\n", x.PLZ);
	printf("Ort..............%s\n", x.ort);
	printf("Geburtsjahr......%d\n", x.geburtsjahr);
}

int main(void)
{
	struct address adresse1={
		"Marcel",
		"Lecram",
		.ort = "München"	
	};

	struct address adresse2={
		.ort="München",
		.PLZ = 81249,
		.nname= "Lecram",
	};

	struct address adresse3={
		.PLZ = 1234,
		"München",
		81249
	};

	ausgabe(adresse1);
	ausgabe(adresse2);
	ausgabe(adresse3);



	return EXIT_SUCCESS;
}

