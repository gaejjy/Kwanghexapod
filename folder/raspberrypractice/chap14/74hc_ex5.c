#include <stdio.h>
#include <wiringPi.h>
#include <stdint.h>
#define SDATA       6   
// Serial Input Data
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
// unsinged 8bit int
void set8(uint8_t value){
   	int i;
	for(i = 0 ; i < 8 ; i++){
	   	int mask = 0b1 << i;
	   	if((value & mask) == 0)
		   	digitalWrite(SDATA, 0);
	   	else digitalWrite(SDATA, 1);
	   	digitalWrite(SHR_CLK, 0); //
	   	digitalWrite(SHR_CLK, 1); //
   	}
// letch
   	digitalWrite(STR_CLK, 0); //
   	digitalWrite(STR_CLK, 1); //
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
   	allclear();
   	for(i = 0 ; i < 10 ; i++){
	   	set8(0b10101010);
		delay(100);
	   	set8(0b01010101);
		delay(100);
   	}
   	return 1; 
}
