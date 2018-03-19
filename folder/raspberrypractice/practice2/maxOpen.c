#include<stdio.h>
#include<unistd.h>
int main(void)
{
   	printf("OPEN_MAX:%ld\n", sysconf(_SC_OPEN_MAX)); return 1;
}	
