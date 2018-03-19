#include<stdio.h>

int main(void)
{
   	FILE *fp;
   	char szName[] = "advc";
   	char szName2[1024];
   	char szBuf[1024];
   	int no = 10, no2;
	if((fp = fopen("./test", "w+")) == NULL){
	   	fprintf(stderr, "fopen error\n");
	   	return 1;
   	}
   	fprintf(fp, "name:%s no:%d\n", szName, no);
   	rewind(fp);
   	fscanf(fp, "name:%s no:%d\n", szName2, &no2);
   	fclose(fp);
   	fprintf(stdout, "name:%s no:%d\n", szName2, no2);
	strcpy(szBuf, "name:sanghun no:1101144127");
   	sscanf(szBuf, "name:%s no:%d", szName2, &no2);
   	fprintf(stdout, "name:%s no:%d\n", szName2, no2);
   	return 0;
}


