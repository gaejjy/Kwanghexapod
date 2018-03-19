#include <stdio.h>
#include <wiringPi.h>
#define SDATA       6    // Serial Input Data
#define STR_CLK     13   // Storage Register Clock(LATCH)
#define SHR_CLK     19   // Shift Register Clock
#define SHR_CLEAR   26   // Shift Register Clear
int main(void)
{
   	int i;
   	if(wiringPiSetupGpio() == -1){ // wiringPi
	   	fprintf(stderr, "wiringPiSetupGpio() erorr\n");
	   	return 1; 
	}
	pinMode(SDATA, OUTPUT);
   	pinMode(STR_CLK, OUTPUT);
   	pinMode(SHR_CLK, OUTPUT);
   	pinMode(SHR_CLEAR, OUTPUT);
   	digitalWrite(SHR_CLEAR, 0);
   	digitalWrite(SHR_CLEAR, 1);
   	digitalWrite(STR_CLK, 0);
   	digitalWrite(STR_CLK, 1);   // latch
for(i = 0 ; i < 32 ; i++){
   	digitalWrite(SDATA, i%2);   // serial data
   	digitalWrite(SHR_CLK, 0);
   	digitalWrite(SHR_CLK, 1);   // shift
   	digitalWrite(STR_CLK, 0); 
  	digitalWrite(STR_CLK, 1);   // latch
   	delay(400);
}
return 1;
}

