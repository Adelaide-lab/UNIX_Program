#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "lib/tlpi_hdr.h"
#define MAX_BUF 1024

int main(int agrc, char **argv)
{
	int fd;
	int j=0;
        int flag=O_RDWR;
        mode_t perms=S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IWOTH|S_IROTH;
	ssize_t numRead;

	char buf[MAX_BUF+1];
	fd=open(argv[1],flag,perms);
	while((numRead=read(fd,buf,MAX_BUF))!=0)
		printf("%s,%d",buf,j++);
	
	
	}
