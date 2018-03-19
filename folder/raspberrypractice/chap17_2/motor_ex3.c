#include <stdio.h>
#include <wiringPi.h>
#define INPUT1 5
#define INPUT2 6
#define INPUT3 27
#define INPUT4 17
int main(void)
{
	int i;
	wiringPiSetupGpio();
	pinMode(INPUT1, OUTPUT);
	pinMode(INPUT2, OUTPUT);
	pinMode(INPUT3, OUTPUT);
	pinMode(INPUT4, OUTPUT);
	for(i = 0 ; i < 3 ; i++){
		digitalWrite(INPUT1, HIGH);
		digitalWrite(INPUT2, LOW);
		digitalWrite(INPUT3, HIGH);
		digitalWrite(INPUT4, LOW);
		delay(500);
		digitalWrite(INPUT1, LOW);
		digitalWrite(INPUT2, HIGH);
		digitalWrite(INPUT3, LOW);
		digitalWrite(INPUT4, HIGH);
		delay(500);
	}
	digitalWrite(INPUT1, LOW);
	digitalWrite(INPUT2, LOW);
	digitalWrite(INPUT3, LOW);
	digitalWrite(INPUT4, LOW);
	return 0;
}
