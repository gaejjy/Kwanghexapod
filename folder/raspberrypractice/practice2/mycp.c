#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define PERM 0644

int main(int argc, char* argv[])
{
	int nSrcFd,nDstFd;
	ssize_t nRead = 0;
	ssize_t nWrite = 0;

	char buf[1024] = {0};

	char* szSrcFilePath = argv[1];
	char* szDstFilePath = argv[2];

	if((nSrcFd = open(szSrcFilePath,O_RDONLY)) == -1)
	{
		printf("Couldn't open : filePath =%s",szSrcFilePath);
		exit(0);
	}

	if((nDstFd = creat(szDstFilePath, PERM)) == -1)
	{
		printf("Couldn't creat : filePath=%s",szDstFilePath);

		exit(0);
	}

	while((nRead = read(nSrcFd,buf,1024))>0)
	{
		if(write(nDstFd,buf,nRead) < nRead)
	   	{
		   	printf("Couldn't write");
		   	close(nDstFd);
		   	close(nSrcFd);
		   	exit(0);
	   	}
	   	nWrite += nRead;
	   	memset(buf,0,sizeof buf);
	}
   	close(nDstFd);
   	close(nSrcFd);
   	if(nRead == -1)
   	{
	   	printf("Couldn't read");
	   	exit(0);
   	}
   	printf("nWrite = %d", nWrite);
   	return 1;
}


