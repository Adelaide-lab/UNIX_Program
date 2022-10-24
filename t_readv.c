#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char **argv)
{
	printf("hello, don't be sad(^v^) \n");
	int fd;
	struct iovec iov[3];
	struct stat myStruct;
	int x;
#define STR_SIZE 100
	char str[STR_SIZE];
	int fd;
	struct iovec iov[3];
	ssize_t numRead,totRequired;
	
	if (agrc != 2 || strcmp(argv[1],"help") == 0)
		usageErr("%s file\n", argv[0]);

	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
		errExit("open");
	totRequired = 0;
		
	iov[1].iov_base = &x;
	iov[1].iov_len  = sizeof(x);
	totRequired+= iov[1].iov_len;
	
	iov[0].iov_base = &myStruct;
	iov[0].iov_len  = sizeof(struct stat);
	totRequired+= iov[0].iov_len;

	iov[2].iov_base = str;
	iov[2].iov_len  = sizeof(str);
	totRequired+= iov[2].iov_len;

	numRead = readv(fd,iov,3);
}
