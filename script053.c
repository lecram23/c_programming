#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int c, counter=0;

	printf("Bitte Eingabe machen : ");

	while((c=getchar())!= '\n'){
		if((c!=' ') && (c != '\t'))
				counter ++;
	}

	printf("Anzahl der Zeichen beträgt %d Zeichen\n", counter-1);

	return EXIT_SUCCESS;
}
