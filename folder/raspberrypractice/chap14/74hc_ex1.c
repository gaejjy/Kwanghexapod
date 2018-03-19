#include <stdio.h>
#include <wiringPi.h>
#define SDATA       6    // Serial Input Data
#define STR_CLK     13   // Storage Register Clock(LATCH)
#define SHR_CLK     19   // Shift Register Clock
#define SHR_CLEAR   26   // Shift Register Clear
int main(void)
{
   	if(wiringPiSetupGpio() == -1){ // wiringPi
   	fprintf(stderr, "wiringPiSetupGpio() erorr\n");
   	return 1;
}
	pinMode(SDATA, OUTPUT);
   	pinMode(STR_CLK, OUTPUT);
   	pinMode(SHR_CLK, OUTPUT);
   	pinMode(SHR_CLEAR, OUTPUT);
	digitalWrite(SHR_CLEAR, 1);
	// serial data 
	digitalWrite(SDATA, 1);
	// shift
   	digitalWrite(SHR_CLK, 0);
   	digitalWrite(SHR_CLK, 1);
	// letch
   	digitalWrite(STR_CLK, 0);
   	digitalWrite(STR_CLK, 1);
	return 1;
}
