#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <stdint.h>
#define SDATA       6    // Serial Input Data
#define STR_CLK     13   // Storage Register Clock(LATCH)
#define SHR_CLK     19   // Shift Register Clock
#define SHR_CLEAR   26   // Shift Register Clear
#define DIGIT1      23   // first digit
#define DIGIT2      24   // second digit
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
// unsinged 8bit int
void set8(uint8_t value)
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
int main(void) {                        //abcdefg
   	uint8_t arr[] = {   ~0b11111100, //0
	   	~0b01100000, //1
	   	~0b11011010, //2
	   	~0b11110010, //3
	   	~0b01100110, //4
	   	~0b10110110, //5
	   	~0b00111110, //6
	   	~0b11100100, //7
	   	~0b11111110, //8
	   	~0b11100110 };//9

init();
pinMode(DIGIT1, OUTPUT);
pinMode(DIGIT2, OUTPUT);
for(;;)
{
   	digitalWrite(DIGIT1, HIGH);
   	digitalWrite(DIGIT2, LOW);
   	set8(arr[0]);
   	delay(1000);
digitalWrite(DIGIT1, LOW);
digitalWrite(DIGIT2, HIGH);
set8(arr[1]);
delay(1000);
}
return 1;
}

