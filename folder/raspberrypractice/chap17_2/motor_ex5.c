#include <stdio.h>
#include <wiringPi.h>
#define INPUT1 5
#define INPUT2 6
#define PWM1 13
#define INPUT3 27
#define INPUT4 17
#define PWM2 12
int main(void)
{
	int i;
	wiringPiSetupGpio();
	pinMode(INPUT1, OUTPUT);
	pinMode(INPUT2, OUTPUT);
	pinMode(PWM1, PWM_OUTPUT);
	pinMode(INPUT3, OUTPUT);
	pinMode(INPUT4, OUTPUT);
	pinMode(PWM2, PWM_OUTPUT);
	digitalWrite(INPUT1, HIGH);
	digitalWrite(INPUT2, LOW);
	digitalWrite(INPUT3, HIGH);
	digitalWrite(INPUT4, LOW);
	for(i = 0 ; i < 1024 ; i++)
	{
		pwmWrite(PWM1, i);
		pwmWrite(PWM2, i);
		if(i % 100 == 0)
			printf("PWM : %d\n", i);
		delay(10);
	}
	delay(3000);
	digitalWrite(INPUT1, LOW);
	digitalWrite(INPUT3, LOW);
	return 0;
}
