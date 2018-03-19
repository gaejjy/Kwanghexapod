#include <stdio.h>
#include <wiringPi.h>
#define SDATA       6    // Serial Input Data
#define STR_CLK     13   // Storage Register Clock(LATCH)
#define SHR_CLK     19   // Shift Register Clock
#define SHR_CLEAR   26   // Shift Register Clear
void allclear(void)
{
   	digitalWrite(SHR_CLEAR, 0);
   	digitalWrite(SHR_CLEAR, 1);
   	digitalWrite(STR_CLK, 0);
   	digitalWrite(STR_CLK, 1);   // latch
}
void set(int index)
{
 
	int i;
   	digitalWrite(SDATA, 1);
   	digitalWrite(SHR_CLK, 0);
   	digitalWrite(SHR_CLK, 1);
   	digitalWrite(SDATA, 0);
   	for(i = 0 ; i < index ; i++){
	   	digitalWrite(SHR_CLK, 0);
	   	digitalWrite(SHR_CLK, 1);   // shift
   	}
   	digitalWrite(STR_CLK, 0);
   	digitalWrite(STR_CLK, 1);   // latch
}
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
	for(i = 0 ; i < 100 ; i++){
	   allclear();
	   set(i%8);
	   delay(100);
   	}
	return 1;
}

