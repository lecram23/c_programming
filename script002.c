#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int number1, number2; 
	
	printf("Please enter a number :");
	scanf("%d", &number1);

	printf("Please enter a second number : ");
	scanf("%d", &number2);

	if(number1 > number2)
		printf("Number one is bigger\n");
	else if(number2 > number1)
		printf("Number two is bigger\n");
	else if(number1==number2)
		printf("Both numbers are equal\n");


	
	return EXIT_SUCCESS;
}
