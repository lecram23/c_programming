/*
 * This small program is guessing a word. Since the user typed in a correct word the
 * letter will be displayed. After guessing the whole word the user has won.
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSUCHE 5
#define TRUE 1
#define FALSE 0
#define MAX 50 


static char hidden_word[MAX];
static char hidden_tmp_word[MAX];

static char HIDDEN = '-';

int guess_word(char);
int print_word(char);
int check_word(void);

int guess_word(char word){
	
	int i=0;
	for(i=0;i<strlen(hidden_word);i++){
		if(hidden_word[i] == word)
			return TRUE;
		else
			return FALSE;
	}
}

int check_word(){
	int i = 0;
	int letter_counter = 0;
	for(i=0;i<strlen(hidden_word);i++){
		if(hidden_tmp_word[i] == hidden_word[i] ){
			letter_counter ++;
			if(letter_counter == strlen(hidden_word))
					return 999;
		}
		else
			return FALSE;
	}
}

int print_word(char character){

	int i=0, offset;
	for(i=0;i<strlen(hidden_word);i++){
		if(hidden_word[i] == character){
			hidden_tmp_word[i] = hidden_word[i];
			offset++;
		}

		printf("%c", hidden_tmp_word[i]);
	}

	printf("\n");

	check_word() == TRUE? offset = 999 : offset;

	return offset;
}

void initialize_tmp_array(){
	int i;
	for(i=0; i<strlen(hidden_word);i++)
		hidden_tmp_word[i] = HIDDEN;
}

int main(void)
{
	char input = ' ';
	int offset = 0;
	strcpy(hidden_word, "AUTO");
	initialize_tmp_array();

	while(offset != 999){
		print_word(input);
		printf("Please enter a character A-Z: ");
		scanf("%c", &input);
		offset = print_word(input);
			
		if(offset == 0)
			printf("Sorry, but there is no letter %c in the word\n", input);
		else if(offset == 1)
			printf("Great, you found a right letter\n");
	}

}
