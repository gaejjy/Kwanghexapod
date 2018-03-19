#include<stdio.h>
#include<stdlib.h>
int main(void)
{
   	FILE* fp;
   	fpos_t pos;
   	if((fp = fopen("./data","r")) == NULL){
	   	fprintf(stderr, "fopen error\n");
	   	exit(1);
   	}
   	pos.__pos = 10;
   	if(fsetpos(fp, &pos) != 0)
	   	fprintf(stderr, "fsetpos\n");
   	if(fgetpos(fp, &pos) != 0)
	   	fprintf(stderr, "fgetpos\n");
   	printf("pos:%ld\n", pos.__pos);
   	printf("sizeof:%ld\n", sizeof(pos.__pos));
   	fclose(fp);
   	return 0;
}

