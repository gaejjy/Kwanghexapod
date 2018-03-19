#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <wiringPi.h>


#define BUFFSIZE 4096





char MorseChar[42][10]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----",".-.-.-",".----.","--..--","-.-.--","..--..","-..--."};

int main(int argc, char *argv[])
{
	FILE  *fp;
	FILE  *fp2;
	int pathsize;
	int argv1size;
	int argv2size;
	int i;
	int c;
    int fpsize;	
	char *szNewFilePath = "./";
	char *readFilePath;
	char *morseFilePath;
	char buf[BUFFSIZE] ={0};
	
	wiringPiSetupGpio();
    fpsize = 0;
    pinMode(26,OUTPUT); /* use GPIO 26 */
    digitalWrite(26,0);
	digitalWrite(26,1);
	if(argc != 3)
	{
		printf("usage :./crdeatenewfile [FileName] [morsefile]\n");
	   	exit(1);
	}

	/*****************************for reading word file********************/
    pathsize = strlen(szNewFilePath);
	argv1size = strlen(argv[1]);
    readFilePath = (char*)malloc(sizeof(char) *(pathsize+argv1size)+1);
	strcpy(readFilePath,szNewFilePath);
	strcat(readFilePath,argv[1]);
	/*********************************************************************/
	
    /*****************************for making file*************************/
    argv2size = strlen(argv[2]);
	morseFilePath = (char*)malloc(sizeof(char) *(pathsize+argv2size)+1);
	strcpy(morseFilePath,szNewFilePath);
    strcat(morseFilePath,argv[2]);
	/*********************************************************************/

    if((fp = fopen(readFilePath, "r+")) == NULL){
	   	fprintf(stderr, "Error open readfile\n");
	    exit(1);
	}

    if((fp2 = fopen(morseFilePath, "wb")) == NULL){
	   	fprintf(stderr, "Error open create morsefile\n");
		exit(1);
	}
  

	do
	{
		c = fgetc(fp);
		if(c == '\n')break;

		if(c>96)
		{
           i = c - 'a';
		   
		}
		else if(c>64 && c<91)
		{
		}
		else
		{
			switch(c)
			{


			}
		}
       
	}while(c !=EOF);
    





}
    

