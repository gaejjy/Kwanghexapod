#include<stdio.h>
typedef struct
{
   	char name[10];
   	long total;
}ITEM;
int main(void)
{
   	ITEM items[2] = {{"shchoi82",20},{"advc",30}};
   	ITEM items2[2];
   	FILE *fp,*fp2;
   	int nread;
   	int i;
   	if((fp = fopen("./test4", "w")) == NULL){
	   	fprintf(stderr, "fopen error\n");
	   	return 1;
   	}
   	if(fwrite(items, sizeof(ITEM), 2, fp) != 2){
	   	fprintf(stderr, "fwrite error\n"); 
		return 1;
   	}
   	fclose(fp);
if((fp2 = fopen("./test4", "r")) == NULL){
   	fprintf(stderr, "fopen error\n");
   	return 1;
}
nread = fread(items2, sizeof(ITEM), 2, fp2);
printf("nread:%d\n", nread);
for(i = 0 ; i < nread ; i++){
   	printf("name : %s\n", items2[i].name);
   	printf("total : %ld\n", items2[i].total);
}
fclose(fp2);
return 0;
}

