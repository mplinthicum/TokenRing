#include "header.h"

struct sockaddr_in serveraddr;

int main(int argc, char **argv){

	int fd;
	char buffrecv[88], buffsend[80];
	
	/* Form the server address. */
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = PORT_NO;
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	/* Open the socket. */
	if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		ReportError("RECEIVER socket creation error");
	}
	
	/* Connect to the server. */
	if(connect(fd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0){
		ReportError("RECEIVER socket connection error");
	}
	
	while(1){
		
		bzero(buffrecv, sizeof(buffrecv));
		if(read(fd, buffrecv, sizeof(buffrecv)) < 0){
			ReportError("RECEIVER read error");
		}
		
		printf("RECEIVER SAYS: %s\n", buffrecv);
		
		bzero(buffsend, sizeof(buffsend));
		strcpy(buffsend, "Neat.");
		if(write(fd, buffsend, sizeof(buffsend)) < 0){
			ReportError("RECEIVER write error");
		}
	}
}
