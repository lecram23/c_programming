#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	char cmd[200];
	char dir[200]; 

	printf("Gib einen Namen für deinen Ordner ein : "); 
	scanf("%s", dir);
	strcpy(cmd, "mkdir ");
	strcat(cmd, dir);

	printf("File : %s", cmd);
	//system(cmd);

	return EXIT_SUCCESS;
}
