#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF 255
#define TRUE 1


int main(void)
{
	size_t len;
	char *str = NULL;
	char puffer[BUF];

	printf("Ein dynamisches char-Array für Strings\n");
	printf("Eingabe machen : ");

	fgets(puffer, BUF, stdin);

	str=malloc(strlen(puffer)+1);

	if(NULL == str)
	{
		printf("Kein virtueller RAM mehr vorhanden ....!");
		return EXIT_FAILURE;
	}

	strcpy(str, puffer);

	printf("Weitere Eingabe oder beendet mit \"END\"\n");

	while(TRUE)
	{
		fgets(puffer, BUF, stdin);

		if(strcmp(puffer, "end\n")==0 || strcmp(puffer, "END\n")==0)
			break;

		len = strlen(str);

		str = realloc(str, strlen(puffer)+len+1);

		if(NULL==str){
			printf("Kein virtueller RAM mehr vorhanden .... !");
			return EXIT_FAILURE;
		}

		// Hinten anhängen
		strcat(str, puffer);
	
	}

	printf("Ihre Eingabe lautete: \n"); 
	printf("%s", str);
	free(str);

	return EXIT_SUCCESS;
}
