#include<unistd.h>
#include<stdio.h>
int main(void)
{
   	printf("%d\n", symlink("./file", "slink"));
   	return 0;
}

