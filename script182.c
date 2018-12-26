#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char str[] = "Have a lot11 of fun";
	char *p;
	char ch = '1';

	p = (char *)memchr(str, ch, 10);
	if (NULL == p)
		printf("%c kommt nicht in den ersten 10 Bytes vor\n", ch);
	else
		printf("%c gefunden an Pos. %d\n", ch, p-str); 

	return EXIT_SUCCESS;
}
