#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *p;

	p=malloc(sizeof(int));

	if(p!=NULL){
		*p=99;
		printf("Allokation erfolgreich...\n");
		printf("Allokation hat %d Bytes\n", sizeof(int));
	}else{
		printf("Kein virtueller RAM mehr verfügbar ...\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
