#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "lib/include/tlpi_hdr.h"

int main(int agrc, char **argv)
 {
        int fd;
        int accessMode,ex;
        int flag=O_WRONLY|O_CREAT;
        mode_t perms=S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IWOTH|S_IROTH;

        fd=open(argv[1],flag,perms);
	ex=fcntl(fd,F_GETFL);
	if(ex == -1)
		errExit("fcntl");
	accessMode=ex & O_ACCMODE;
	if(accessMode==O_WRONLY||accessMode==O_RDWR)
		printf("file is writable\n");	
         }
