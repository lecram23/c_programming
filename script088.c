#include <stdio.h>
#include <stdlib.h>

#define MAX 80

int main(void)
{
	FILE *quelle;
	char datei1[MAX], datei2[MAX];
	char puffer[MAX];

	printf("Welche Datei wollen Sie als erste lesen : "); 
	scanf("%s", datei1);

	printf("Welche Datei wollen Sie anschleßend lesen : ");
	scanf("%s", datei2); 

	quelle = fopen(datei1, "r");

	if(NULL == quelle){
		fprintf(stderr, "Fehler beim Oeffnen von %s\n", datei1);
		return EXIT_FAILURE;
	}

	while(fgets(puffer, MAX, quelle) != NULL)
		fputs(puffer, stdout);

	printf("\n");
	freopen(datei2,"r",quelle);

	while(fgets(puffer, MAX, quelle) != NULL)
		fputs(puffer, stdout); 

	return EXIT_SUCCESS; 
}
