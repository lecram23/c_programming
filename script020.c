#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int *value;
	int size, i=0;

	printf("Wie viele WErte benötigen Sie : ");
	scanf("%d", &size);

	value = malloc(size*sizeof(int));

	if(NULL == value){
		printf("Fehler bei malloc ....!!\n");
		return EXIT_FAILURE;
	}

	while(i<size){
		printf("wert für value[%d] eingeben : ", i);
		scanf("%d", (value+i));
		i++;
	}

	printf("Hier Ihre Werte\n");

	for(i=0;i<size;i++)
		printf("value[%d] = %d\n", i, *(value+i));




	return EXIT_SUCCESS;
}
