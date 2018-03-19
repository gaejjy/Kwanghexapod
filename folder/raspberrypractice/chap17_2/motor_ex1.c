#include <stdio.h>
#include <wiringPi.h>
#define INPUT1 5
#define INPUT2 6
int main(void)
{
	int i;
	wiringPiSetupGpio();
	pinMode(INPUT1, OUTPUT);
	pinMode(INPUT2, OUTPUT);
	for(i = 0 ; i < 5 ; i++){
		digitalWrite(INPUT1, HIGH); // A ..
		digitalWrite(INPUT2, LOW);
		delay(500);
		digitalWrite(INPUT1, LOW); // B ..
		digitalWrite(INPUT2, HIGH);
		delay(500);
	}
	digitalWrite(INPUT1, LOW);
	digitalWrite(INPUT2, LOW);
	return 0;
}
