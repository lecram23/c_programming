#include <stdio.h>
#include <stdlib.h>

#define MAX 30

struct address{
	char vname[MAX];
	char nname[MAX];
	long PLZ;
	char ort[MAX];
	int geburtsjahr;
}adressen;

void ausgabe(struct address);

void ausgabe(struct address x){
	printf("\n\nSie gaben :\n\n");
	printf("Vorname.............%s", x.vname);
	printf("Nachname............%s", x.nname);
	printf("Postleitzahl........%ld\n", x.PLZ);
	printf("Ort.................%s", x.ort);
	printf("Geburtsjahr.........%d\n", x.geburtsjahr);
}

int main(void)
{
	printf("Vorname          :");
	fgets(adressen.vname, MAX, stdin);

	printf("Nachname         :");
	fgets(adressen.nname, MAX, stdin);

	printf("Postleitzahl     :");

	do{
		scanf("%ld", &adressen.PLZ);
	}while(getchar() != '\n');

	printf("Wohnort          :");
	fgets(adressen.ort, MAX, stdin);
	printf("Geburtsjahr      :");

	do{
		scanf("%4d", &adressen.geburtsjahr);
	}while(getchar()!='\n');

	ausgabe(adressen);

	return EXIT_SUCCESS;
}
