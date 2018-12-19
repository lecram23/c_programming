#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

static char text[MAX];

int save_text(char c){
	printf("angekommen : %c\n", c);
	int strlength = strlen(text);
	char str[MAX];
	str[0] = c;
        strcat(text, str);
	if(strlen(text) > strlength)
		return TRUE;
	else
		return FALSE;

}

int main(void)
{
	int c;

	while((c=getchar() != '.')){
	       char input = putchar(c);
	       printf("%c", input);
	}

	printf("Du hast folgendes eingegeben: \n");
	printf("------------Ausgabe----------\n");
	printf("%s",text);

	return EXIT_SUCCESS;
}
