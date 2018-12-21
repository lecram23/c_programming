#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a,b,c, tmp; // 4,9,1
	int inner, outer;

	printf("Please enter 3 numbers\n");

	printf("1. Number: ");
	scanf("%d", &a); 

	printf("2. Number : "); 
	scanf("%d", &b);

	printf("3. Number : "); 
	scanf("%d", &c);

	int values[] = {a,b,c};	

	printf("Deine Werte sind: \n");

	for(int i=0;i<3;i++)
		printf("%d\n", values[i]);

	// quick bubble sort for sorting values
	
	for(inner=0;inner<3;inner++){
		for(outer=0;outer<3;outer++){
			if(values[inner] > values[outer]){
				tmp = values[inner]; 
				values[inner] = values[outer];
				values[outer] = tmp;
			}
		}
	}

	printf("Biggest num is %d ", values[0]);

	return EXIT_SUCCESS; 
}
