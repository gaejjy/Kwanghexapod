#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main(void)
{
   	int fd, len;
   	char buf[20];
	if ((fd = open("tempfile", O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
   	{
	   	printf("open error\n");
	   	return 1;
   	}
   	unlink("tempfile");
   	if(write(fd, "How are you?", 12) != 12)
   	{
	   	printf("write error\n");
	   	return 1;
   	}
   	lseek(fd, 0L, SEEK_SET);
	if((len = read(fd, buf, sizeof(buf))) <=0){
	   	printf("read error\n");
	   	return 1;
   	}
	
   	else buf[len] = '\0';
	printf("%s\n", buf);
   	close(fd);
   	if ((fd = open("tempfile", O_RDWR)) < 0)
   	{
	   	printf("Second open error\n");
	   	return 1;
   	}
   	close(fd);
   	return 0;
}


