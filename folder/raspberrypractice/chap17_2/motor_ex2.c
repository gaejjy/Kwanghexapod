#include <stdio.h>
#include <wiringPi.h>
#define INPUT3 27
#define INPUT4 17
int main(void)
{
	int i;
	wiringPiSetupGpio();
	pinMode(INPUT3, OUTPUT);
	pinMode(INPUT4, OUTPUT);
	for(i = 0 ; i < 5 ; i++){
		digitalWrite(INPUT3, HIGH); // A ..
		digitalWrite(INPUT4, LOW);
		delay(500);
		digitalWrite(INPUT3, LOW); // B ..
		digitalWrite(INPUT4, HIGH);
		delay(500);
	}
	digitalWrite(INPUT3, LOW);
	digitalWrite(INPUT4, LOW);
	return 0;
}

