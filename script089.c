#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *datei;

	printf("Wir schreiben in eine Datei \"log.txt\"\n");
	datei = freopen("test.txt","a+", stdout);
	printf("Dieser text steht in der datei: ");
	fclose(datei);

	return EXIT_SUCCESS;
}
