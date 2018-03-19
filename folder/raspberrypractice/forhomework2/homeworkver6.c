#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <wiringPi.h>


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
    char buf[BUFFSIZE] ={0};
	char readbuf[BUFFSIZE];
    bufcount = 0;
    wiringPiSetupGpio();

    pinMode(26,OUTPUT); /* use GPIO 26 */
    digitalWrite(26,0);
    digitalWrite(26,1);
 
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
    
    /*******************************************************************/
	/************Write until get EOF******************************/
   
   
	while(nowinput = read(STDIN_FILENO,buf,BUFFSIZE) >0)
		{
                       
                 printf("before check i will show you buf....%s\n",buf);
                printf("now buf size is %d\n",strlen(buf));
                
                 for(i = 0; i <strlen(buf);i++)
                 {
                  if( ((int)buf[i] <97 && (int)buf[i] >122)   ||   ((int)buf[i] <48 && (int)buf[i] >81) || ((int)buf[i] <65 && (int)buf[i] >90) )
                  {
                     if( ((int)buf[i] == 46) ||((int)buf[i] == 44) || ((int)buf[i] == 63) ||((int)buf[i] == 96)
                          ||((int)buf[i] == 33) ||((int)buf[i] == 47) ||((int)buf[i] == 32) ||(buf[i] == '\t')  )
                      {continue;}
                     else
                      {

                     printf("you input wrong character....\n"); 
                     exit(1);
                      }
                  }
                 }
                  
                  if((fd = open(FullNewFilePath,O_RDWR | O_CREAT | O_EXCL,0644)) == -1)
	          {
		  fprintf(stderr, "Couldn't open.. : filePath=%s\n", FullNewFilePath);
		  exit(1);
                  }

                 
		
                if(write(fd,buf,strlen(buf))<0)
			{printf("input error...\n");}
	        else
		   	{
			   	printf("after write show buf... %s \n",buf);

				break;
                
			}		
            
			
		}
    


        digitalWrite(26,0);
	close(fd);
	return 0;

}
