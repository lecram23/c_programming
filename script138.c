#ifdef __unix__
	#include <unistd.h>
#elif __WIN32 || _MS_DOS_
	#include <dir.h>
#else
	#include <direct.h>
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

int main(void)
{
	char puffer[MAX];
	char home[MAX];

	if(getenv("HOME") == NULL){
		printf("getenv(\"HOME\") findet nichts\n");
		return EXIT_FAILURE;
	}

	// Das Heimatsverzeichnis nach home
	strncpy(home, getenv("HOME"), MAX -1);
	home[MAX-1] = '\0';

	// Working directory lesen
	if(getcwd(puffer, sizeof(puffer)) == NULL){
		fprintf(stderr, "Fehler bei getcwd ...\n");
		return EXIT_FAILURE;
	}

	// Sind wie schon im Heimatverzeihnis?
	if(strcmp(home, puffer) == 0)
		printf("Wie sind daheim : %s\n", puffer);
	else{
		chdir(home);
		printf("backat home: %s \n", getcwd(puffer, sizeof(puffer)));
	}

	return EXIT_SUCCESS;
}
