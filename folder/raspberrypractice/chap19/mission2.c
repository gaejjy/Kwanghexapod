#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#define EXIT_SUCC 0
#define EXIT_FAIL 1

#define SW   23

int main()
{
   	int fd;
   	int data;
	int dr;
	

	setbuf(stdout, NULL);
	if(wiringPiSetupGpio() == -1){
	   	fprintf(stdout, "Unable to start wiringPi : %s\n", strerror(errno)); return EXIT_FAIL; }
	// ... .. ... . .. ..
   	if((fd = serialOpen("/dev/ttyAMA0", 115200)) < 0)
   	{
	   	fprintf(stderr, "Unable to open serial device : %s\n", strerror(errno));
	   	return EXIT_FAIL;
   	}

	pinMode(SW, INPUT);
   	pullUpDnControl(SW, PUD_UP);



	printf("\nRaspberry Pi UART daemon start\n");
   	serialPuts(fd, "Here I'm the Raspberry Pi.\r\n");  // to serial
   	serialPuts(fd, "Write a message.\r\n");             // to serial

	while(1)
   	{
	   	delay(10);
	   	if((dr = digitalRead(SW)) == 1){
		  serialPuts(fd,":-------\r");
	   	}
	   	else
	   	{
		   	serialPuts(fd,":--___--\n");
		   	
	   	}
   	}


}

