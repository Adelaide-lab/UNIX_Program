#include <sys/stat.h>
#include <fcntl.h>
#include "lib/include/tlpi_hdr.h"

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc,char** argv)
{
	int inputFd,outputFd,openFlags;
	mode_t filePerms;
	ssize_t numRead;
	char buf[BUF_SIZE];
	memset(buf,0,sizeof(buf));
	
	if(argc!=3 || strcmp(argv[1],"--helpi") == 0)
	   usageErr("%s old-file new-file\n",argv[0]);

	inputFd=open(argv[1],O_RDONLY);

	if(inputFd==-1)
	   errExit("opening file %s",argv[1]);
	
	openFlags=O_CREAT|O_WRONLY|O_TRUNC;
	filePerms=S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|
		  S_IROTH|S_IWOTH;			
	outputFd=open(argv[2],openFlags,filePerms);
	printf("%d\n",outputFd);
	if(outputFd==-1)
	   errExit("opening file %s",argv[2]);
	
	printf("fxxk you!");
	while((numRead = read(inputFd,buf,BUF_SIZE))>0)
	   if(write(outputFd,buf,numRead)!=numRead)
		fatal("couldn't wirte whole buffer");
	if(numRead == -1)
	   errExit("read");

	if(close(inputFd) == -1)
	   errExit("close Input");

	if(close(outputFd) == -1)
	   errExit("close Output");

	exit(EXIT_SUCCESS);	
}
