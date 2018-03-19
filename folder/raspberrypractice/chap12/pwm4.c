#include <stdio.h>
#include <wiringPi.h>
#define LED1 13
int main(void)
{
   	wiringPiSetupGpio();
	pinMode(LED1, OUTPUT);
	int i;
	int j;
	i = 10;
	while(1)
   	{
      for(j = 0;j<10;j++)
	  {
	   	digitalWrite(LED1, HIGH);
	   	delay(i+j);
	   	digitalWrite(LED1, LOW);
	   	delay(i-j);
	  }
	  
   	}
	return 0;
}
