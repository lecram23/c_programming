#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(void)
{
	FILE *fp;
	int ret; 
	wchar_t wStr[] = 
		L"Ein einfaches Beispiel für Breitzeichen";

	fp=(fopen("testfile.txt", "w+"));

	if(NULL == fp){
		printf("Konnte Datei nicht öffnen\n");
		exit(EXIT_FAILURE);
	}

	// Wide orientiert setzen = 1
	ret = fwide(fp,1);

	if(ret<=0){
		fprintf(stderr, "Konnte nicht auf Breitzeichen umstellen\n");
		exit(EXIT_FAILURE);
	}

	fputws(wStr, fp); 
	return EXIT_SUCCESS;
}
