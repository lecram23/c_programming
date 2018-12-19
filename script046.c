#include <stdio.h>
#include <stdlib.h>
#include <dos.h>

#define LPT1_PORT 0x378

struct status{
	unsigned 	:3;
	unsigned fehler :1;
	unsigned online :1;
	unsigned papier :1;
	unsigned empfang:1;
	unsigned busy   :1;
}LPT1_status;

void druckerstatus(char *statusanzeiger){
	*stausanzeiger = inp(LPT1_PORT+1) & 0xF8;
}

int main(void)
{
	druckerstatus ((char *) &LPT1_staus);

	if(LPT1_status.busy && LPT1_status.online){
		printf("Drucker ist bereit!\n");
		return EXIT_SUCCESS;
	}else if(!LPT1_status.online)
		printf("Drucker nicht online!\n");
	else if(LPT1_status.papier)
		printf("Kein Papier vorhanden!\n");
	else	
		printf("Drucker nicht bereit!\n"); 


	return EXIT_SUCCESS;
}
