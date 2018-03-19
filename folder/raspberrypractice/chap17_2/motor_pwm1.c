#include <stdio.h>
#include <wiringPi.h>
#define MOTOR_PWM 12
int main(void)
{
	wiringPiSetupGpio();
	pinMode(MOTOR_PWM, PWM_OUTPUT);
	// .. 0 ~ 1024
	pwmWrite(MOTOR_PWM, 0);
	delay(1000);
	pwmWrite(MOTOR_PWM, 400);
	delay(1000);
	pwmWrite(MOTOR_PWM, 700);
	delay(1000);
	pwmWrite(MOTOR_PWM, 900);
	delay(1000);
	pwmWrite(MOTOR_PWM, 1024);
	delay(1000);
	pwmWrite(MOTOR_PWM, 0);
	delay(1000);
	return 0;
}

