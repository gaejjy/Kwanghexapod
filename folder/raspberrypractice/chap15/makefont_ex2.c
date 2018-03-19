#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define COL 5
uint8_t font85[][COL] = { 0x7F, 0x88, 0x88, 0x88, 0x7F,  //  A
   	0xFF, 0x91, 0x91, 0x91, 0x6E,  //  B
   	0x7E, 0x81, 0x81, 0x81, 0x42,  //  C
   	0xFF, 0x81, 0x81, 0x42, 0x3C,  //  D
   	0xFF, 0x91, 0x91, 0x91, 0x81}; //  E
int main(void)
{
   	int i, j, k, total;
   	uint8_t mask; // # of font
   	total = sizeof(font85) / COL / sizeof(uint8_t);
   	for(k = 0 ; k < total ; k++){
	   	for(i = 7 ; i >= 0 ; i--){
	  		// row
		   	mask = 0b1 << i;
		   	for(j = 0 ; j < COL ; j++){
			   	// col
			   	if((mask & font85[k][j]) != 0)
				   	printf("o ");
			   	else printf(". ");
			}
		   	printf("\n")
				;
	   	}
	   	printf("\n");
   	}
   	return 0;
} 
