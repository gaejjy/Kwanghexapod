#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#define EXIT_SUCC 0
#define EXIT_FAIL 1

#define LED1 3

int main()
{
	int fd;
	int data;
	setbuf(stdout, NULL);
	if(wiringPiSetupGpio() == -1){
		fprintf(stdout, "Unable to start wiringPi : %s\n", strerror(errno));
		return EXIT_FAIL;
	}

    pinMode(LED1, OUTPUT);



	// ... .. ... . .. ..
	if((fd = serialOpen("/dev/ttyAMA0", 115200)) < 0)
	{
		fprintf(stderr, "Unable to open serial device : %s\n", strerror(errno));
		return EXIT_FAIL;
	}


	printf("\nRaspberry Pi UART daemon start\n");
	serialPuts(fd, "Here I'm the Raspberry Pi.\r\n"); // to serial
	serialPuts(fd, "Write a message.\r\n"); // to serial
	serialPuts(fd, "<select a menu.\r\n");
	serialPuts(fd, "<0 : LED OFF >.\r\n");
	serialPuts(fd, "<1 : LED ON  >.\r\n");

	while(1){
		data = serialGetchar(fd); // from serial
		if(data == '1')
		{
			printf("led on...\n");
			digitalWrite(LED1, 1);      
			delay(3000);

		}
		else if(data == '0')
		{
			printf("led off..\n");
			digitalWrite(LED1, 0);      
			delay(3000);

		}
		else printf("you should type 1 or 2\n");
	}
	return EXIT_SUCC;
}
