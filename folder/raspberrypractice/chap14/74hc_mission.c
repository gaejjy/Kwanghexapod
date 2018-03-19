#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <stdint.h>
#define SDATA       6    // Serial Input Data
#define STR_CLK     13   // Storage Register Clock(LATCH)
#define SHR_CLK     19   // Shift Register Clock
#define SHR_CLEAR   26   // Shift Register Clear
void allclear(void);

void init(void)
{
   	if(wiringPiSetupGpio() == -1){ // wiringPi
	   	fprintf(stderr, "wiringPiSetupGpio() erorr\n");
	   	exit(1);
   	}
   	pinMode(SDATA, OUTPUT);
   	pinMode(STR_CLK, OUTPUT);
   	pinMode(SHR_CLK, OUTPUT);
   	pinMode(SHR_CLEAR, OUTPUT);
   	allclear();
}
void allclear(void)
{
   	digitalWrite(SHR_CLEAR, 0);
   	digitalWrite(SHR_CLEAR, 1);
   	digitalWrite(STR_CLK, 0);
   	digitalWrite(STR_CLK, 1);   // latch
}
void set8(uint8_t value) // unsinged 8bit int
{
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
   	uint8_t arr[] = {   
		0b00000000, 0b00011000, 0b00111100, 0b01111110, 0b11111111,0b01111110, 0b00111100,0b00011000};
	init();
	while(1)
	{
	for(i = 0 ; i < sizeof(arr) ; i++){
	   	set8(arr[i]);
	   	delay(100);
   	}
	}
   	return 1;
}

