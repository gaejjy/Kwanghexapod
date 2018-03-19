#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
   	int fd;
	char *szFilePath = "./newFile";

	if((fd = open("./file1", O_RDONLY | O_TRUNC)) == -1)
	{
	   	fprintf(stderr, "Couldn't open.. : filePath=%s\n", szFilePath);
	   	exit(1);
   	}
	printf("fd:%d\n", fd);
	close(fd);
   	return 0;
}
