#include <stdio.h>
#include <stdlib.h>

struct uhrzeit{
	unsigned int stunde;
	unsigned int minute;
	unsigned int sekunde;
};

struct datum{
	unsigned int tag;
	unsigned int monat;
	int jahr;
}; 

struct termin{
	struct datum d;
	struct uhrzeit z;
}t;

int main(void)
{
	// Termin am 18.12.2018
	struct datum d = {18,12,2018};
	struct uhrzeit u = {13,59,59};
	struct termin t = {d,u};

	printf("Termin am ");
	printf("%u.%u.%d um ", t.d.tag, t.d.monat, t.d.jahr);
	printf("%u.%u.%u Uhr \n\n", t.z.stunde, t.z.minute, t.z.sekunde);

	printf("Neuen Termin eingeben !!\n\n");
	printf("Tag...............: ");
	scanf("%u", &t.d.tag);

	printf("Monat.............: ");
	scanf("%u", &t.d.monat);

	printf("Jahr..............: "); 
	scanf("%u", &t.d.jahr);
	
	printf("Stunde............: ");
	scanf("%u", &t.z.stunde);

	printf("Minute............: ");
	scanf("%u", &t.z.minute);

	printf("Sekunde...........: ");
	scanf("%u", &t.z.sekunde);


	printf("Dein neuer Termin ist \n\n");

	printf("%u.%u.%u um %u:%u:%u\n", t.d.tag, t.d.monat, t.d.jahr, t.z.stunde, t.z.minute,t.z.sekunde);


	return EXIT_SUCCESS;
}


