#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int main(void)
{
	int *p = malloc(SIZE*sizeof(int));

	if(p!=NULL)
	{
		*p=99;
		*(p+1)=100;
		*(p+2)=200;
		printf("Allokation erfolgreich ...\n");
	}else{
		printf("Kein virtueller RAM mehr verfügbar ....\n");
		return EXIT_FAILURE;
	}

	printf("%d %d \n", p[0], p[1]);
	printf("%d %d \n", *p, *(p+1));
	printf("%d %d \n", *p, *(p+2));

	return EXIT_SUCCESS;
}
