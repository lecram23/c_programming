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

// Funktion zur Ausgabe des Satzes

void ausgabe(struct address * struct_ptr)
{
	printf("\n\nSie gaben : \n\n");
	printf("Vorname.........%s", struct_ptr->vname);
	printf("Nachname........%s", struct_ptr->nname);
	printf("Postleitzahl....%ld\n", struct_ptr->PLZ);
	printf("Ort.............%s", struct_ptr->ort);
	printf("Geburtsjahr.....%ld\n", struct_ptr->geburtsjahr);
}

struct address *eingabe(void){
	static struct address *adressen;

	adressen = malloc(sizeof(struct address));
	printf("Vorname      : ");
	fgets(adressen->vname, MAX, stdin);

	printf("Nachname     : ");
	fgets(adressen->nname, MAX, stdin);

	printf("Postleitzahl : ");	
	do{
		scanf("%d", &adressen->PLZ);
	}while(getchar() != '\n');

	printf("Ort          : ");
	fgets(adressen->ort, MAX, stdin);

	printf("Geburtsjahr  : ");
	do{
		scanf("%d", &adressen->geburtsjahr);
	}while(getchar() != '\n');
	
	return adressen;
}

int main(void)
{
	struct adres *adresse1, *adresse2;

	adresse1 = eingabe(); 
	printf("--------------------\n");
	adresse2 = eingabe();

	ausgabe(adresse1);
	ausgabe(adresse2);

	return EXIT_SUCCESS;
}
