#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int fd;
	char *szNewFilePath = "./newFile";

	if((fd = open(szNewFilePath, O_RDWR | O_CREAT | O_EXCL | O_TRUNC , 0644)) == -1)
	{
		fprintf(stderr,"Couldn't open.... : filePath=%s",szNewFilePath);
		exit(1);
	}
	close(fd);
	return 0;
}
