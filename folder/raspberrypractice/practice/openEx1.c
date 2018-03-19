#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define  PERM 0644

int main()
{
	int fd;
	char *szNewFilePath = "./newFile";

	if((fd = open(szNewFilePath, O_WRONLY | O_CREAT, PERM)) == -1)
	{
		fprintf(stderr,"Couldn't open.... : filePath:%s",szNewFilePath);
		exit(1);
	}
	close(fd);
	return 0;
}
