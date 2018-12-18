#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 10

int main(void)
{
	char puffer[BUF];
	char *dyn_string;

	printf("Ein Text mit max. 80 Zeichen: ");
	fgets(puffer, BUF, stdin);

	dyn_string=malloc(strlen(puffer)+1);

	if(dyn_string!=NULL)
		strncpy(dyn_string, puffer,strlen(puffer)+1);
	else{
		printf("Konnte keinen speicherplatz reservieren\n");
		return EXIT_FAILURE;
	}
	
	printf("%s", dyn_string);
	free(dyn_string);

	return EXIT_SUCCESS;
}
