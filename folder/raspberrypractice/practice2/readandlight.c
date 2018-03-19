#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <wiringPi.h>
#define EXIT_SUCC  0
#define EXIT_FAIL  1

typedef struct TAG_GPIOCTL_DATA{
   	int pinNo;
   	int onTime;
   	int offTime;
   	int repeat;
}GPIOCTL_DATA;


int main(void)
{
	char *fname = "gpio_data";
   	int fd;
   	const int DATA_SIZE = sizeof(GPIOCTL_DATA);
	GPIOCTL_DATA data;

   	int i;
	int pinNo;
	int repeat;
	int ontime;
	int offtime;
   	wiringPiSetupGpio();
	if((fd = open(fname, O_RDONLY)) == -1){
	   	fprintf(stderr, "open error\n");
	   	return 1;
   	}
   	if(read(fd, &data, DATA_SIZE) != DATA_SIZE){
	   	fprintf(stderr, "read error\n");
	   	exit(1);
   	} 
    pinNo = data.pinNo;
	repeat = data.repeat;
	ontime = data.onTime;
	offtime = data.offTime;
	pinMode(pinNo,OUTPUT);
	digitalWrite(pinNo, 0);
    for(i = 0;i<repeat;i++)
		
	{
	  digitalWrite(pinNo,1);
      delay(ontime*100);
      digitalWrite(pinNo,0);
      delay(offtime*100);
	}
return 0;
}


