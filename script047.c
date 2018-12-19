#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MAX 15

struct data{
	char date[MAX];
	unsigned int flag;
	char eigentuemer[MAX]; 
	char password[MAX];
};

int main(void)
{
	struct data newfile = {"testfile",0,"itsme", "believe"};
	
	printf("Vom Anfang zur Strukturvariable flag    : %d Bytes\n", offsetof(struct data,flag));
	printf("Vom Anfang zur Strukturvariable owner   : %d Bytes\n", offsetof(struct data, eigentuemer));
	printf("Vom Anfang zur Strukturvariable passwort: %d Bytes\n", offsetof(struct data, password));


	return EXIT_SUCCESS;
}
