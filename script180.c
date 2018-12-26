#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigfunc(int sig){
	if(sig == SIGABRT)
		printf("Demonstaion von SIGABRT\n");
}

int main(void)
{
	signal(SIGABRT, sigfunc); 
	abort();
	return EXIT_SUCCESS;
}
