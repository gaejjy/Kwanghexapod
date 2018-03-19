#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define COL 5
uint8_t font85[COL] = { 0x7F, 0x88, 0x88, 0x88, 0x7F };  //  A
int main(void)
{
   	int i, j;
   	uint8_t mask;
   	for(i = 7 ; i >= 0 ; i--){      // row
		
	   	mask = 0b1 << i;
	   	for(j = 0 ; j < COL ; j++){ // col
		   	if((mask & font85[j]) != 0){
			   	printf("o ");
		   	}else{
			   	printf(". ");
		   	}
	   	}
	   	printf("\n");
   	}
   	return 0;
} 
