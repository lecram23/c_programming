#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define CHARS 20

void chomp(char *str){
	size_t p = strlen(str);
	str[p-1] = '\0'; 
}

void is_long(char *str){
	static long val;
	char *stop_ptr = NULL;

	val = strtoul(str, &stop_ptr, 10);

	if(errno == ERANGE){
		printf("Werteueber- bzw. unterlauf!!!\n");
		exit(EXIT_FAILURE);
	}

	if(!val){
		printf("Wert konnte nicht umgewandelt werden\n");
		exit(EXIT_FAILURE);
	}

	if(*stop_ptr){
		printf("Kein korrekter long-Wert : %s\n", str);
		printf("Fehler der Umwandlung ab POS. : %s\n", stop_ptr);
		printf("Umgewandelt ---> %ld\n", val);
	}else
		printf("Yeah ! Korrekter long-Wert : %ld\n", val); 
}

void is_double(char *str){
	static double val;
	char *stop_ptr = NULL;

	val = strtod(str, &stop_ptr);
	if(errno == ERANGE){
		printf("Werteueber- bzw. unterlauf!!!!\n");
		exit(EXIT_FAILURE);
	}

	if(!val){
		printf("Wert konnte nicht umgewandelt werden\n");
		exit(EXIT_FAILURE);
	}

	if(*stop_ptr){
		printf("Kein korrekter double-Wert : %s\n", str);
		printf("Fehler der Umwandlung ab Pos.: %s\n", stop_ptr); 
		printf("Umgewandelt -> %lf\n", val);
	}else
		printf("Yeah ! Korrekter double-Wert: %lf\n", val);
}


int main(void)
{
	char val[CHARS];
	printf("Bitte geben Sie einen long-Wert ein: ");
	fgets(val, CHARS, stdin);
	chomp(val);
	is_long(val);

	printf("Bitte geben Sie einen double-Wert ein : ");
	fgets(val, CHARS, stdin);
	chomp(val);
	is_double(val);

	return EXIT_SUCCESS; 
}











