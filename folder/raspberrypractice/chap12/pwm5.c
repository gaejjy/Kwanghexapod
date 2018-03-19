#include <stdio.h>
#include <wiringPi.h>
#define LED 12
int main(void)
{
   	wiringPiSetupGpio();
   	pinMode(LED, PWM_OUTPUT);
	// .. 0 ~ 1024
   	pwmWrite(LED, 0);
   	delay(1000);
   	pwmWrite(LED, 400);
   	delay(1000);
   	pwmWrite(LED, 700);
   	delay(1000);
   	pwmWrite(LED, 900);
   	delay(1000);
   	pwmWrite(LED, 1024);
   	delay(1000);
	return 0;
}

