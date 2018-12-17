#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char ch = 'H';
	int i = 10;

	// First assigning pointer to text
	void *ptr;
	
	ptr=(char*)&ch;

	*(char*)ptr = ch;

	printf("%c", ptr);

	return EXIT_SUCCESS;
}
