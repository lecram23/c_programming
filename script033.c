#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 30

struct address{
	char vname[MAX];
	char nname[MAX];
	long PLZ;
	char ort[MAX];
	int geburtsjahr;
};

int cmp_structs(struct address *str1, struct address *str2)
{
	
	// Vorname gleich und ...
	if(strcmp(str1->vname, str2->vname) == 0 &&
			// Nachname gleich und ...
			strcmp(str1->nname, str2->nname) == 0 &&
			 	// PLZ gleich und ...
				str1->PLZ - str2->PLZ == 0 &&
					// Ort gleich und ...
					strcmp(str1->ort, str2->ort) == 0 &&
						// Geburtsjahr
						str1->geburtsjahr-str2->geburtsjahr == 0)
							return 0;
	else
		return 1;
}


int main(void)
{
	struct address adresse1 = {"Marcel", "Lecram", 1234, "München", 1991};
	struct address adresse2 = {"Marcel", "Leccram", 1234, "München", 1991};

	int result = 0;

	result = cmp_structs(&adresse1, &adresse2);

	if(result == 0)
		printf("%s", "EQUALS");
	else
		printf("%s", "NOT EQUALS");
	return EXIT_SUCCESS;
}


