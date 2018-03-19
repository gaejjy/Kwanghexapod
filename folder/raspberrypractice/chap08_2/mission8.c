#include<stdio.h>
#include <wiringPi.h>



int main(void)
{
   	FILE *fp;
   	int pin;
   	int on;
   	int off;
   	int repeat;
    int i; 
    wiringPiSetupGpio();


	if((fp = fopen("./gpio_data2", "r")) == NULL){
	   	fprintf(stderr, "fopen error\n");
	   	return 1;
   	}
   	fscanf(fp, "pin:%d\n", &pin);
   	fscanf(fp, "on:%d\n", &on);
   	fscanf(fp, "off:%d\n", &off);
   	fscanf(fp, "repeat:%d\n", &repeat);

    pinMode(pin,OUTPUT);
	digitalWrite(pin, 0); 

	delay(1000);


	for(i = 0;i<repeat;i++)
	{
     digitalWrite(pin, 1);
     delay(100*on);
     digitalWrite(pin, 0);
     delay(100*off);
	}
}	
