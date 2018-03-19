#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <wiringPi.h>

#define ON 1
#define OFF 0
#define SIZE 2048
#define LED1 3 

void ReadAndLight(char *in_fname, char *in_buf);

int main(int argc, char *argv[])
{

	 char in_buf[SIZE] = {0};


	if(wiringPiSetupGpio() == -1)
		        exit(1);

	pinMode(LED1, OUTPUT);

	 if(argc < 2)
		 {
			 fprintf(stderr,"usage : msg2mores filename1 [filename2]\n");
			 digitalWrite(LED1, OFF);
			 exit(1);
		 }

	 if(access(argv[1], 0))
		 {
			 fprintf(stderr, "'%s' file not found.\nfail!\n", argv[1]);
			 digitalWrite(LED1, OFF);
			 exit(1);
		 }
	 ReadAndLight(argv[1],in_buf);

	 return 0;
}

void ReadAndLight(char *in_fname, char *in_buf)
{
    FILE *fp;
    char tmp_buf[SIZE] = {0};
    int i;
    if((fp = fopen(in_fname, "r")) != NULL)
	 {
		 int size = 0;
		 fread(in_buf, SIZE, 1, fp);
		 size = strlen(in_buf)-1;

	     for(i = 0; i < size; i++)
		 {
		   char target = in_buf[i];
		   switch(target)
		   {
		     case '-' :digitalWrite(LED1, 1); 
			           delay(1500);
					   digitalWrite(LED1,0);
					   delay(500); 
			           break;
		     case '.' :digitalWrite(LED1, 1);
					   delay(500);
					   digitalWrite(LED1,0);
					   delay(500); 
			           break;
			 case ' ' :digitalWrite(LED1,0);
					   delay(1500);
					   break;
		   }
	   	 }
     }
	else
	{
		fprintf(stderr, "fopen() is error\nfail!\n");
	    fclose(fp);
		exit(1);
	}
}

