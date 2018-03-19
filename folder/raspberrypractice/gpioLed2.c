#include <stdio.h>
#include <wiringPi.h>
#define LED1 5
#define LED2 6
#define LED3 13
#define LED4 19
#define LED5 26
#define EXIT_SUCC 0
#define EXIT_FAIL 1
int
main(void)
{
	int i;
	wiringPiSetupGpio();
	
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);
	pinMode(LED5, OUTPUT);
	
	digitalWrite(LED2, 0);
	digitalWrite(LED3, 0);
	digitalWrite(LED4, 0);
	digitalWrite(LED5, 0);
	delay(1000);

	
	digitalWrite(LED2, 1);
	delay(200);
	digitalWrite(LED2, 0);
	digitalWrite(LED3, 1);
	delay(200);
	digitalWrite(LED3, 0);
	digitalWrite(LED4, 1);
	delay(200);
	digitalWrite(LED4, 0);
	digitalWrite(LED5, 1);
	delay(200);
	digitalWrite(LED5, 0);
	return 0;
}
