#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

struct index{
	int seite;
	char titel[MAX];
};

int main(void)
{
	int i;
	struct index lib[3];

	lib[0].seite=312;
	strcpy(lib[0].titel, "Arrays von Strukturen");
	
	lib[1].seite=320;
	strcpy(lib[1].titel, "Strukturen in Skrukturen");
	
	lib[2].seite=900;
	strcpy(lib[2].titel, "Anhang");

	for(i=0;i<3;i++)
		printf("Seite %4d\t %-30s\n", lib[i].seite, lib[i].titel);

	return EXIT_SUCCESS;

}
