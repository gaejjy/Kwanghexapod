#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <stdint.h>
#define SDATA       6    // Serial Input Data
#define STR_CLK     13   // Storage Register Clock(LATCH)
#define SHR_CLK     19   // Shift Register Clock
#define SHR_CLEAR   26   // Shift Register Clear
void allclear(void);

void init(void) {
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
	   	} else{
		   	digitalWrite(SDATA, 1);
	   	}
	   	digitalWrite(SHR_CLK, 0);
	   	//
	   	digitalWrite(SHR_CLK, 1); //
   	} // letch
   	digitalWrite(STR_CLK, 0); //
   	digitalWrite(STR_CLK, 1); //
}
int main(void)
{
   	int i;
   	uint16_t arr[] = {  0b1000000000000000, 0b0100000000000000, 0b0010000000000000,
	0b0001000000000000, 0b0000100000000000, 0b0000010000000000, 0b0000001000000000, 0b0000000100000000, 0b0000000010000000, 0b0000000001000000, 0b0000000000100000, 0b0000000000010000, 0b0000000000001000, 0b0000000000000100, 0b0000000000000010, 0b0000000000000001};
init();
for(i = 0 ; i < 16 ; i++){ set16(arr[i]); delay(100);
} return 1;
}

