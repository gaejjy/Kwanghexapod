#include <stdio.h>
#include <stdlib.h>
int main(void)
{
   	FILE  *fp;
   	int c;
   	if((fp = fopen("test", "r")) == NULL)
   	{
	   	fprintf(stderr,"fopen error\n");
	   	return 1; 
	}
   	c = fgetc(fp);
   	printf("%c", c);
   	c = fgetc(fp);
   	printf("%c", c);
   	c = fgetc(fp);
   	printf("%c", c);
	ungetc(c, fp);
	c = fgetc(fp);
   	printf("%c", c);
	fclose(fp); return 0;
}

