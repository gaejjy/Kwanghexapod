#include<stdio.h>
#include<unistd.h>
int main(void)
{
	printf("stdin._fileno:%d\n", stdin->_fileno);
	printf("stdout._fileno:%d\n", stdout->_fileno);
	printf("stderr._fileno:%d\n", stderr->_fileno);
	return 0;
}
