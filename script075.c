#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORT "ROLF"
#define MAX 10

int main(void)
{
	char pswd[MAX];

	printf("Passwort : ");
	scanf("%s", pswd); 

	if(strcmp(PASSWORT, pswd) == 0)
		printf("Welcome \n");
	else
		printf("Wrong password ");

	return EXIT_SUCCESS;
}
