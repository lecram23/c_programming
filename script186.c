#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char credit_card[21] = "123456-marcel";
	char *ptr = strchr(credit_card, '-');

	*ptr++;

	// Die letzten vier Zeichen der Kreditkarten ummer nicht angeben
	
	memset(ptr, '*', 6);
	printf("%s\n", credit_card);

	return EXIT_SUCCESS;
}
