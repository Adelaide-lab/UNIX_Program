#define _GNU_SOURCE
#include "lib/include/tlpi_hdr.h"

extern char **environ;

int main (int argc,char *argv[])
{
	char **ep;	
	int j;
	
	for(j=1; j<argc; j++)
		if(putenv(argv[j]) == -1)
			errExit("putenv:%s",argv[j]);
	
	unsetenv("BYE");
	
	for(ep=environ;*ep!=NULL;ep++)
		puts(*ep);
	
	exit(EXIT_SUCCESS);
	}
