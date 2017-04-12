#include "header.h"

void get_input(char* buffer, int length){
	/* Clear buffer and reset pointer. */
	bzero(buffer, length);
	
	printf("Put your shit here >> ");
	fgets(buffer, length, stdin);
	
	/* Read in and get rid of extra characters. */
	if(buffer[strlen(buffer) - 1] != '\n'){
		printf("TOO LONG\n");
		while(fgetc(stdin) != '\n');
	}
	
	buffer[strlen(buffer) - 1] = '\0';
}
