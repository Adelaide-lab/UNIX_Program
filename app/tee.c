#include "tlpi_hdr.h"
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_BUFFER 1024


int main(int argc,char **argv)
{
	int opt;
	int append_option=0;
	char *filename =NULL;


	if(argc <= 2)
	{
		filename=argv[1];
		printf("Given file:%s\n",filename);
			}
	else{
	while((opt=getopt(argc,argv,":a:"))!=-1)
	{
	  switch(opt){
			
			case 'a':
				printf("Given file:%s\n",optarg);
				filename=optarg;
				append_option=1;
				break;
			case ':':
				printf("option needs a value\n");
				break;
			case '?':
				printf("unknown option:%c\n",optopt);
				break;
				}
					}
	}

	int flag=O_WRONLY|O_CREAT|(append_option?O_APPEND:O_TRUNC);
	int perms=S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IWOTH|S_IROTH;
	int fd=open(filename,flag,perms);
        	
	if(fd==-1)
	   errExit("open file %s failed",filename);
		
	char buf[MAX_BUFFER+1];
	memset(buf,0,sizeof(buf));

	ssize_t size_byte;
	ssize_t write_byte;

	if((size_byte=read(STDIN_FILENO,buf,MAX_BUFFER))==-1)
		errExit("read file %s failed",filename);
	else if((write_byte=write(fd,buf,size_byte))!=size_byte)
		errExit("write file %s failed",filename);
	  
	if(close(fd)==-1)
		errExit("close file %s failed",filename);
}

