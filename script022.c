#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int main(void)
{
	int n=0, max=10, z, i;
	int *zahlen=NULL; 
	
	// Wir reservieren Speicher für 10 int-werte mit calloc
	zahlen = calloc(max, sizeof(int));

	if(NULL == zahlen){
		printf("Kein virtueller RAM mehr verfügbar ...!");
		return EXIT_FAILURE;
	}

	printf("Zahlen eingeben --- Beenden mit 0\n");

	while(TRUE){
		printf("Zahl (%d) eingeben : ", n+1);
		scanf("%d", &z);

		if(z==0)
			break;

		// Reservierung von Speicher während der Laufzeit des Programmes mit realloc
		if(n>=max){
			max+=max;
			zahlen=realloc(zahlen,max*sizeof(int));

			if(NULL==zahlen){
				printf("Kein virtueller RAM mehr vorhanden ....!");
				return EXIT_FAILURE;
			}

			printf("Speicherplatz reserviert "\
				"(%d Bytes\n", sizeof(int)*max);
		}

		zahlen[n++] = z;
	}

	printf("Folgende Zahlen wurden eingebeben -> \n\n");

	printf("N is %d\n", n);

	for(i=0;i<n;i++)
		printf("Number %d = %d\n",i+1, zahlen[i]);

	free(zahlen);


	return EXIT_SUCCESS;
}
