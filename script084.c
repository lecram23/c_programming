#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STRING_MAX 8192

int wort_begrenzer(char);

int wort_begrenzer(char c){
	return (c == ' ' || c == '\n' || c == '\t' || c == '\0' ||
		c== '.' || c == ',' || c == ';' || c == '!' || c== '=');
}


void chomp(char *str){
	size_t p = strlen(str);
	str[p-1] = '\0';
}

int main(int argc, char *argv[]){
	FILE *file, *copy;

	char alt_string[STRING_MAX+1], neu_string[STRING_MAX+1],
	     such_wort[STRING_MAX+1], replace_wort[STRING_MAX+1],*zgr;

	char puffer[STRING_MAX +1];
	int such_wortlen, i=0, w;
	size_t len = 0;

	if(argc < 2){
		fprintf(stderr, "Verwendung: %s datei\n", *argv); 
		return EXIT_FAILURE;
	}

	file = fopen(argv[1], "r"); // Datei zum Lesen öffnen
	copy = fopen(argv[1], "r+");  // Datei zum Schreiben öffnen

	if(file == NULL || copy == NULL){
		printf("Fehler bei fopen () ....\n");
		return EXIT_FAILURE;
	}

	alt_string[0] = '\0';

	while((fgets(puffer, STRING_MAX+1, file)) != NULL){
		len += strlen(puffer)+1;
		if(len < STRING_MAX)
			strcat(alt_string, puffer);
		else{
			printf("Puffergroesse ueberschritten !\n");
			break;
		}
	 }

	neu_string[0] = '\0';

	printf("Welches Wrot wollen Sie ersetzen : ");
	fgets(such_wort, STRING_MAX, stdin);
	chomp(such_wort);

	such_wortlen = strlen(such_wort);

	for(w = 0; w < such_wortlen; w++){
		if(wort_begrenzer(such_wort[w])){
			printf("Keine Wortbegrenezer im Suchwort!!!\n");
			return EXIT_FAILURE;
		}
	}

	printf("Durch welches Wort wollen Sie ersetzten : ");
	fgets(replace_wort, STRING_MAX, stdin);

	chomp(replace_wort);
	i= 0;

	while(1){
		if((zgr=strstr(&alt_string[i], such_wort)) == NULL){
			strcat(neu_string, &alt_string[i]);
			break;
		}else{
			strncat(neu_string, &alt_string[i], zgr-&alt_string[i]);
			
			if((zgr-&alt_string[0]==0 || 
			  wort_begrenzer(*(zgr-1))) &&
			  wort_begrenzer(*(zgr+such_wortlen))){
				strcat(neu_string, replace_wort);
				i+= zgr + such_wortlen-&alt_string[i];
			}else{
				strncat(neu_string, zgr, 1);
				i+=zgr +1 - &alt_string[1];
			}

		}
	}
	strcpy(alt_string, neu_string);
	fputs(alt_string, copy);
	neu_string[0] = '\0';
	return EXIT_SUCCESS;
}





