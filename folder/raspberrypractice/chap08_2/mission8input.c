#include<stdio.h>
int main(void)
{
   	FILE *fp;
   	int pin;
   	int on;
   	int off;
   	int repeat;
	if((fp = fopen("./gpio_data2", "w")) == NULL){
	   	fprintf(stderr, "fopen error\n");
	   	return 1;
   	}
   	printf("gpio pin number:");
   	scanf("%d", &pin);
   	printf("on period(sec):");
  	scanf("%d", &on);
   	printf("off period(sec):");
   	scanf("%d", &off);
   	printf("repeat:");
  	scanf("%d", &repeat);
	fprintf(fp, "pin:%d\n", pin);
   	fprintf(fp, "on:%d\n", on);
   	fprintf(fp, "off:%d\n", off);
   	fprintf(fp, "repeat:%d\n", repeat);
   	fclose(fp);
	return 0;
}

