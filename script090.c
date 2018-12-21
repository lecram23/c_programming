#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char pfad[100];

	printf("Welche Datei wollen Sie loeschen ?\n");
	printf("Bitten wenn nötig gültigen Pfad angeben.\n"); 
	printf("Eingabe :> ");
	scanf("%99s", pfad);

	if((remove(pfad)) < 0){
		fprintf(stderr, "Fehler beim Löschen von %s", pfad);
		return EXIT_FAILURE;
	}else
		printf("Datei %s wurde erfolgreich gelöscht");

	return EXIT_SUCCESS;
}
