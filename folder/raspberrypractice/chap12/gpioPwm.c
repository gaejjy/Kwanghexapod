#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>
#define PWM 14          // gpio 14
#define EXIT_SUCC  0
#define EXIT_FAIL  1
int main(void)
{
   	int x = 0;
   	int orient = 0;
   	if(wiringPiSetupGpio() == -1)
	   	return EXIT_FAIL;
   	softPwmCreate (PWM, 0, 100) ;
   	while(1)
   	{
	   	if(orient == 0)
		{
		   	x += 2;
		   	if(x == 100) orient = 1;
	   	} else {
		   	x -= 2;
		   	if(x == 0) orient = 0;
	   	} softPwmWrite (PWM, x);
	   	delay(10);
   	}
   	return EXIT_SUCC;
}

