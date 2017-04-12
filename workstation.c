#include "header.h"

long M = 2147483647;

struct sockaddr_in serveraddr, clientaddr;

int main(int argc, char **argv){

	int fd, s, data_fd;
	int clientaddr_len = sizeof(clientaddr);
	char buffsend[82], buffrecv[80], frame[88];

	/* Form the server address. */
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = PORT_NO;
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    /* Open the socket. */
    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        ReportError("SENDER socket creation error");
    }

    /* Bind the socket to serveraddr. */
    if(bind(fd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0){
        ReportError("SENDER socket bind error");
    }

    /* Listen for incoming connections. */
    listen(fd, 1);
    
    /* Wait for and accept connection from receiver. */
    if((s = accept(fd, (struct sockaddr*)&clientaddr, &clientaddr_len)) < 0){
		ReportError("SENDER accept error");
	}
	
	while(1){
	
		get_input(buffsend, sizeof(buffsend));
		
		/* Write to the receiver. */
		if(write(s, buffsend, sizeof(buffsend)) < 0){
			ReportError("SENDER write error");
		}
		
		bzero(buffrecv, sizeof(buffrecv));
		if(read(s, buffrecv, sizeof(buffrecv)) < 0){
			ReportError("SENDER read error");
		}
		
		printf("SENDER SAYS: %s\n", buffrecv);
	
	}
}
