#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *wday[] = {
	"Sonntag", "Montag", "Dienstag", "Mittwoch",
	"Donnerstag", "Freitag", "Samstag", "??????"
};

int main(void)
{
	struct tm time_check;
	int year, month, day;

	// Jahr, Monat und Tag eingeben zum herausfinden des Wochentages
	
	printf("Jahr : ");
	scanf("%d", &year);

	printf("Monat : ");
	scanf("%d", &month);

	printf("Tag  : "); 
	scanf("%d", &day);

	// Wir füllen unsere Struktur struct tm time_check
	
	time_check.tm_year = year -1900;
	time_check.tm_mon = month -1;
	time_check.tm_mday = day;

	time_check.tm_hour = 0;
	time_check.tm_min = 0;
	time_check.tm_sec = 1;
	time_check.tm_isdst = -1;

	if(mktime(&time_check) == -1)
		time_check.tm_wday = 7; // unbekannter Tag

	// Der Tag des Datums wird ausgegeben
	printf("Dieser Tag ist/war ein %s\n", wday[time_check.tm_wday]);

	return EXIT_SUCCESS;
}
