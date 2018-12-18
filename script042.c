#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct address{
	char vname[MAX];
	char nname[MAX];
	char anschrift[MAX];
	long geburtsjahr;
};

typedef struct address ADRESSE;

int main(void)
{
	ADRESSE myaddress = {
		.vname="Marcel",
		.nname="Lecram",
		.anschrift="Munich",
		.geburtsjahr=2019
	}; 

	printf("Vorname...........%s\n", myaddress.vname);
	printf("Nachname..........%s\n", myaddress.nname);
	printf("Stadt.............%s\n", myaddress.anschrift);
	printf("Geburtsjahr.......%ld\n", myaddress.geburtsjahr);

	return EXIT_SUCCESS;
}
