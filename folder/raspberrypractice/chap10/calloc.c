#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define BUFSIZE 30
int main(int argc, char *argv[])
{
	char *ptr[10];
	char fmt[10];
	int i = 0;
	for(i = 0 ; i < 10 ; i++){
		if((ptr[i] = (char *)calloc(BUFSIZE ,sizeof(char))) == NULL){
			fprintf(stderr, "calloc error\n"), exit(0);
		}
	}
	for(i = 0 ; i < 10 ; i++){
		sprintf(fmt, "string-%02d", i);
		strcpy(ptr[i], fmt);
	}
	for(i = 0 ; i < 10 ; i++)
		printf("ptr[%d] : %s\n", i, ptr[i]);
	return 1;
}

