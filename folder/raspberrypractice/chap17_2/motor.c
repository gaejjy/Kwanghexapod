
#include <stdio.h>
#include <wiringPi.h>
#define MOTOR 12
int main(void)
{
	int i = 0;
	wiringPiSetupGpio();
	pinMode(MOTOR, OUTPUT);
	for(i = 0 ; i < 5 ; i++){
		digitalWrite(MOTOR, HIGH);
		delay(100);
		digitalWrite(MOTOR, LOW);
		delay(100);
	}
	return 0;
}
