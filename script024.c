#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,j,zeile,spalte;

	// Matrix ist Zeiger auf int-Zeiger
	int **matrix;

	printf("Wie viele Zeilen : ");
	scanf("%d", &zeile);

	printf("Wie viele Spalten : ");
	scanf("%d", &spalte);

	// Speicher reservieren für die int-Zeiger (=zeile)
	matrix = malloc(zeile * sizeof(int *));

	if(NULL == matrix){
		printf("Kein virtueller RAM mehr vorhanden ... !");
		return EXIT_FAILURE;
	}

	// Jetzt noch Speicher reservieren für die einzelnen Spalten
	
	for(i=0;i<zeile;i++){
		matrix[i] = malloc(spalte *sizeof(int));
			if(NULL == matrix[i]){
				printf("Kein Speicher mehr für Zeile %d\n", i);
				return EXIT_FAILURE;
			}
	}

	// Mit beliebigen Werten initialisieren
	
	for(i=0;i<zeile;i++)
		for(j=0;j<spalte;j++)
			matrix[i][j] = i+j;

	// Inhalt der Matrix entsprechend ausgeben
	
	for(i=0;i<zeile;i++){
		for(j=0;j<spalte;j++)
			printf("%d", matrix[i][j]);
		printf("\n");
	}

	// Speicherplatz wieder freigeben wichtig1 in umgekehrter Reihenfolge
	
	// Spalten der iten Zeile freigeben
	
	for(i=0;i<zeile;i++)
		free(matrix[i]);

	free(matrix);
	
	return EXIT_SUCCESS;
}
