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
   	if(wiringPiSetupGpio() == -1){
	   	// wiringPi
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
void set16(uint16_t value)
{
   	int i;


	for(i = 0 ; i < 16 ; i++){
	   	int mask = 0b1 << i;
	   	if((value & mask) == 0){
		   	digitalWrite(SDATA, 0);
	   	}
	   	else{
		   	digitalWrite(SDATA, 1);
	   	}
	   	digitalWrite(SHR_CLK, 0); //
	   	digitalWrite(SHR_CLK, 1); //
   	} // letch
   	digitalWrite(STR_CLK, 0); //
   	digitalWrite(STR_CLK, 1); //
}
int main(void)
{ int i; uint8_t row[] = {   0b10000000, 0b01000000, 0b00100000, 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001};
	uint8_t col = 0b00000000; uint16_t tmp; init();
	for(;;) for(i = 0 ; i < 8 ; i++){ tmp = (row[i]<<8) | col; set16(tmp); delay(100); } return 1;
}
