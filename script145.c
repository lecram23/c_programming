#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define MAXWERT 8192

enum {WARN, ERROR, EXIT, MISC};

// Stringtabelle mit Fehlerausgaben

const char *error[] = {
	"Fehlerhafte Eingabe\n",
	"Maximaler Wertebereich ueberschritten\n",
	"Negativer Wert wurde eingegeben\n"
};

void fehler(int kennung, const char *format, ...){
	va_list vargzeiger;
	va_start(vargzeiger, format);

	switch(kennung){
		case 0 : printf("\nAchtung : ");
			 vprintf(format, vargzeiger);
			 break;
		case 1 : printf("\nFehler : ");
			 vprintf(format, vargzeiger);
			 break;
		case 2 : printf("\nProgrammabbruch : ");
			 vprintf(format, vargzeiger);
			 exit(EXIT_FAILURE);
		case 3 : vprintf(format, vargzeiger);
			 break;
		default: printf("\nFalscher Funktionsaufruf\n");
	}

	va_end(vargzeiger);
}

int main(void)
{
	int zahl, ret;

	printf("Eine Zahl zwischen 0-%d:", MAXWERT);
	ret=scanf("%d", &zahl);

	if(ret == 0)
		fehler(EXIT, error[0]);
	else if(zahl > MAXWERT)
		fehler(WARN, error[1]);
	else if(zahl < 0)
		fehler(ERROR, error[2]);
	else
		fehler(MISC, "Eingabe ist in Ordnung\n");

	return EXIT_SUCCESS;
}
