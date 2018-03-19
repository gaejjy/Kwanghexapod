#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<pwd.h>


int main(int argc, char *argv[])
{
   	struct stat buf;
    struct passwd *pass;

   	if(stat(argv[1], &buf) == -1){
	   	printf("stat error\n");
	   	return 1;
   	}
   	printf("file onwer user  : %d\n", buf.st_uid);
   	printf("file owner group : %d\n", buf.st_gid);

    pass = getpwuid(buf.st_uid);

	printf("user ID : %s\n",pass->pw_name);
   	return 0;
} 
