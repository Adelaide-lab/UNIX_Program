#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

int main(int argc, char **argv)
{
	int fd;
	struct iovec iov[3];
	struct stat myStruct;
	int x;
#define STR_SIZE 100
	char str[STR_SIZE];
}
