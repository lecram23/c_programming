#include <stdio.h>
#include <stdlib.h>

typedef unsigned int WORD;
typedef unsigned int BYTE; 

int main(void)
{
	// Word in den Speicher schreiben
	WORD Word = 0x22CCDDEE;
	BYTE *Byte;
	Byte = (BYTE *) &Word;

	if(Byte[0] == ((Word>>0)&0xFF))
		printf("Little Endian Architecture\n");
	if(Byte[0] == ((Word >> 24) & 0xFF))
		printf("Big Endian Architecture\n");

	return EXIT_SUCCESS;
}
