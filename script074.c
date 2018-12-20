#include <stdio.h>
#include <stdlib.h>

#define LINE 80

int main(void)
{
	FILE *quelle;
	char puffer[LINE], name[20];

	printf("Welche Datei wollen Sie zum Lesen oeffnen : ");
	scanf("%s", name);

	if((quelle=fopen(name, "r")) == NULL){
		fprintf(stderr, "Kann %s nicht oeffnen\n", name);
		return EXIT_FAILURE;
	}

	while(fgets(puffer, LINE, quelle))
		fputs(puffer, stdout);

	return EXIT_SUCCESS;
}
