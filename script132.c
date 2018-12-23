#ifdef __unix__
	#include <sys/types.h>
	#include <sys/stat.h>
	#define MODUS ,0711)
#elif __WIN32__ || _MS_DOS_
	#include <dir.h>
	#define MODUS )
#else
	#include <direct.h>
	#define MODUS)
#endif

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char pfadname[200];
	printf("Wie soll der neue Ordner heissen: ");
	scanf("%s", pfadname);

	if(mkdir(pfadname MODUS == -1) 
		printf("Konnte kein neues Verzeichnis erstellen\n");
	else
		printf("Neues Verzeichnis namens %s erstellt\n", pfadname);

	return EXIT_SUCCESS;
}
