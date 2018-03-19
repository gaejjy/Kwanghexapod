#include <stdio.h>
#include <wiringPi.h>
#define LED1 13
int main(void)
{
   	wiringPiSetupGpio();
	pinMode(LED1, OUTPUT);
	while(1)
   	{
	   	digitalWrite(LED1, HIGH);
	   	delay(10);
	   	digitalWrite(LED1, LOW);
	   	delay(10);
   	}
	return 0;
}
