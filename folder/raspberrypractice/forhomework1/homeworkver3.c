#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFSIZE 4096

int main(int argc, char *argv[])
{
    int nowinput;
	int nowread;
	int fd;
	int pathsize;
	int argvsize;
	int bufcount;
    int i;	
	char charac;
	char *szNewFilePath = "./";
    char *FullNewFilePath;
    char buf[BUFFSIZE];
	char readbuf[BUFFSIZE];
    bufcount = 0;
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
	/****file create and check*/
    if((fd = open(FullNewFilePath,O_RDWR | O_CREAT | O_EXCL,0644)) == -1)
	{
		fprintf(stderr, "Couldn't open.. : filePath=%s\n", FullNewFilePath);
		exit(1);
    }
    /*******************************************************************/
	/************Write until get EOF******************************/
   
   
	while(nowinput = read(STDIN_FILENO,buf,BUFFSIZE) >0)
		{
   
			if(write(fd,buf,strlen(buf))<0)
			{printf("input error...\n");}
	        else
		   	{
			   	printf("after write show buf... %s \n",buf);
                
			}		
            
			
		}
    



	close(fd);
	return 0;

}
