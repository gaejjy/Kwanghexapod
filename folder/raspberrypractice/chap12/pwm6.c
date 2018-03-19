#include <stdio.h>
#include <wiringPi.h>
#define LED 12
int main(void)
{
	int i, j;
   	wiringPiSetupGpio();
   	pinMode(LED, PWM_OUTPUT);
	for(i = 0 ; i <= 1024 ; i++)
   	{
	   	pwmWrite(LED, i);
	   	delayMicroseconds(1000);
   	}
	return 0;
}
