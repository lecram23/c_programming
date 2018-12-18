#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct index{
	int seite;
	char titel[30];
};

struct product{
	int article_number;
	char category[30];
};

int main(void)
{
	struct index lib;
	struct product pen;

	lib.seite = 23;
	strcpy(lib.titel, "c-programming");

	pen.article_number = 123456;
	strcpy(pen.category, "Writings");

	printf("%d, %s\n",lib.seite, lib.titel);
	printf("%d, %s\n", pen.article_number, pen.category);

	return EXIT_SUCCESS;
}
