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
		delay(10);
		if(i % 100 == 0)
			printf(".. PWM:%d\n", i);
	}

	for(i = 1024 ; i >= 0 ; i--)
	{
		pwmWrite(LED, i);
		delay(10);
		if(i % 100 == 0)
			printf(".. PWM:%d\n", i);
	}
	pwmWrite(LED, 0);
	return 0;
}
