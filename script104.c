#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct address{
	char first_name[MAX];
	char last_name[MAX];
	char street[MAX];
	int number; 
	int age;
};

void ausgabe(struct address *output){
	
	printf("First name.................%s\n", output->first_name);	
	printf("Last name..................%s\n", output->last_name);
	printf("Street.....................%s\n", output->street);
	printf("Number.....................%d\n", output->number); 
	printf("Age........................%d\n", output->age);
}

void save_to_file(struct address *output){
	FILE *output_file;
	int c;

	output_file = fopen("data.txt", "w+"); 

	if(output_file == NULL){
		printf("Error while loading file \n"); 
		exit(EXIT_FAILURE);
	}

	fwrite(&output, sizeof(output), 5, output_file);
}

int main(void)
{
	struct address data;
	
	printf("-------Output-------\n");
	printf(" Enter details below\n");
	
	printf("First name..........\n");
	scanf("%s", data.first_name);

	printf("Last name...........\n");
	scanf("%s", data.last_name);

	printf("Street..............\n");
	scanf("%s", data.street);

	printf("Number..............\n");
	scanf("%d", &data.number);

	printf("Age.................\n");
	scanf("%d", &data.age);

	ausgabe(&data);
	save_to_file(&data);

	return EXIT_SUCCESS;
}
