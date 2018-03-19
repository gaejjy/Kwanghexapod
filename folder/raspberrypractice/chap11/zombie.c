#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	pid_t pid;
	if((pid = fork()) < 0){
		fprintf(stderr, "fork error\n");
		exit(1);
	}else if(pid == 0){
		printf("I'am Child Porcess : %d\n", getpid());
		printf("Child Porcess end : %d\n", getpid());
		exit(1);
	}else{
		printf("I'am Parent Porcess : %d\n", getpid());
		sleep(10);
		exit(1);
	}
	return 1;
}

