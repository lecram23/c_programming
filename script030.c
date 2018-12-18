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

void ausgabe(struct address *struct_ptr){
	printf("\n\nSie gaben ein:\n\n");
	printf("Vorname...........%s", (*struct_ptr).vname);
	printf("Nachname..........%s", (*struct_ptr).nname);
	printf("Postleitzahl......%ld\n", (*struct_ptr).PLZ);
	printf("Ort...............%s", (*struct_ptr).ort);
	printf("Geburtsjahr.......%ld\n", (*struct_ptr).geburtsjahr);
}

int main(void)
{
	printf("Vorname       :");
	fgets(adressen.vname, MAX, stdin);

	printf("Nachname      :");
	fgets(adressen.nname, MAX, stdin);

	printf("Postleitzahl  :");
	do{
		scanf("%d", &adressen.PLZ);
	}while(getchar() != '\n');

	printf("Wohnort       :");
	fgets(adressen.ort, MAX, stdin);

	printf("Geburtsjahr   :");
	do
		scanf("%d", &adressen.geburtsjahr);
	while(getchar() != '\n');

	ausgabe(&adressen);

	return EXIT_SUCCESS;
}
