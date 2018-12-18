#include <stdio.h>
#include <stdlib.h>

#define MIN_LEN 256

int main(void)
{
	int *ptr;
	char jn;

	static size_t len = 8192; // Speicheranforderung

	do{
		printf("Demo \n");
		ptr = malloc(len);
		// Speicher konnte nicht alloziert werden
		if(ptr == NULL){
			len /= 2; // mit der Hälfte versuchen
			ptr = malloc(len);

			if(ptr == NULL){
				printf("Konnte keinen Speicher alozieren. "\
					"weiter versuchen ? (j/n): ");
			scanf("%c", &jn);
			fflush(stdin);
			}
		}else
			break;
	}while(jn != 'n' && len > MIN_LEN);

	if(len <= MIN_LEN)
		printf("Speicheranforderung abgebrochen\n");
	else
		printf("Speicheranforderung erfolgreich\n");

	return EXIT_SUCCESS;
}
