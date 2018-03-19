#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
	char *ptr = NULL;
	char *tmp = NULL;
	if((ptr = malloc(10)) == NULL)
		fprintf(stderr, "malloc error\n"),exit(1);
	if((tmp = malloc(10)) == NULL)
		fprintf(stderr, "malloc error\n"),exit(1);
	printf("ptr address : 0x%08x\n", ptr);
	printf("tmp address : 0x%08x\n", tmp);
	strcpy(ptr, "123456789" );
	printf("ptr : %s\n", ptr);
	ptr = realloc(ptr, 100);
	printf("after realloc()\nptr address : 0x%08x\n", ptr);
	strcat(ptr, "abcdefghijk" );
	printf("ptr : %s\n", ptr);
	return 1;
}
