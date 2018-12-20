#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORT "ROLF"
#define MAX 10

void chomp(char *);

void chomp(char *str){
	size_t p = strlen(str);
	str[p-1]='\0';
}

int main(void)
{
	char pswd[MAX];

	printf("Passwort : ");
	fgets(pswd, MAX, stdin);
	chomp(pswd);

	if(strcmp(PASSWORT, pswd) == 0)
		printf("Welcome \n");
	else
		printf("Wrong password !!!\n");


	return EXIT_SUCCESS;
}
