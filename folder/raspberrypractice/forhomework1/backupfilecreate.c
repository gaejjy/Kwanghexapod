#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int nowinput;
	int fd;
	int pathsize;
	int argvsize;
	nowinput = 0;

	char *szNewFilePath = "./";
    char *FullNewFilePath;

	if(argc != 2)
	{
		printf("usage :./createnewfile [FileName]\n");
        exit(1);
	}

	/*check string size and combine filepath string and [FileName] string*/
    pathsize = strlen(szNewFilePath);
	argvsize = strlen(argv[1]);

    FullNewFilePath =(char*)malloc(sizeof(char) *(pathsize+argvsize)+1);
    strcpy(FullNewFilePath,szNewFilePath);
	strcat(FullNewFilePath,argv[1]);
	/********************************************************************/
    if((fd = open(FullNewFilePath,O_RDWR | O_CREAT | O_EXCL,0644)) == -1)
	{
		fprintf(stderr, "Couldn't open.. : filePath=%s\n", FullNewFilePath);
		exit(1);
    }
	close(fd);
	return 0;

}
