#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *datei;
	
	datei = fopen("test.txt", "r");

	if(NULL == datei){
		printf("Konnte Datei \"test.txt\" nicht öffnen\n"); 
		return EXIT_FAILURE;
	}else{
		printf("\"test.txt\" wurde erfolgreich eingelesen\n");
		return EXIT_SUCCESS;
	}
}
