#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
   	extern char **environ;
   	int i;
	for(i = 0 ; *(environ+i) != NULL ; i++);
   	printf("env size : %d\n", i);
	putenv("ENVTEST=abcdefg");
	for(i = 0 ; *(environ+i) != NULL ; i++)
	   	printf("%s\n", *(environ+i));
	printf("\n\nenv size : %d\n", i);
   	printf("ENVTEST=%s\n", getenv("ENVTEST"));
	return 1;
}

