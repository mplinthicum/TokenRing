#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <strings.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <string.h>

/* My local hostname: michael-K55VD */

#define ReportError(msg)       {perror(msg); exit(-1);}
#define PORT_NO				   2840

long random();
void srandom(unsigned);
void IntroduceError(char*, double);
char *GenerateData(int);
int Server(void), Client(void);
double floor(double);
char linebuffer[100];
void get_input(char* buffer, int length);


