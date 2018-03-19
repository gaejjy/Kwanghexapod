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
	pwmWrite(PWM1, 0);
	pwmWrite(PWM2, 0);
	delay(1000);
	pwmWrite(PWM1, 400);
	pwmWrite(PWM2, 400);
	delay(1000);
	pwmWrite(PWM1, 700);
	pwmWrite(PWM2, 700);
	delay(1000);
	pwmWrite(PWM1, 900);
	pwmWrite(PWM2, 900);
	delay(1000);
	pwmWrite(PWM1, 1024);
	pwmWrite(PWM2, 1024);
	delay(1000);
	digitalWrite(INPUT1, LOW);
	digitalWrite(INPUT3, LOW);
	return 0;
}
