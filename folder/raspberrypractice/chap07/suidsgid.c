#include<stdio.h>
#include<sys/stat.h>
int main(void)
{
   	struct stat buf;
   	if(stat("/usr/bin/passwd", &buf) == -1){
	   	printf("stat error\n");
	   	return 1;
   	}
   	printf("st_uid : %d\n", buf.st_uid);
   	printf("st_gid : %d\n", buf.st_gid);
   	if(S_ISUID & buf.st_mode) printf("SUID\n");
   	if(S_ISGID & buf.st_mode) printf("SGID\n");
   	return 0;
}

