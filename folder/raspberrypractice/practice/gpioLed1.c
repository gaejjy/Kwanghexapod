#include <stdio.h>
#include <wiringPi.h>
#define LED1 3 // gpio 3
#define EXIT_SUCC 0
#define EXIT_FAIL 1
int
main(void)
{
	if(wiringPiSetupGpio() == -1)
		return EXIT_FAIL;
	pinMode(LED1, OUTPUT);
	while(1) {
		digitalWrite(LED1, 1);
		delay(1000);
		digitalWrite(LED1, 0);
		delay(1000);
	}
	return EXIT_SUCC;
}

