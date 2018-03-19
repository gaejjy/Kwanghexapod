#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define FONT_COL 5      // ... Column
#define BOARD_ROW 8     // board. Row
#define INTERVAL 1;     // .... ....
// 8x5 font ...
uint8_t font85[][FONT_COL] = { 0x7F, 0x88, 0x88, 0x88, 0x7F,  //  A
   	0xFF, 0x91, 0x91, 0x91, 0x6E,  //  B
   	0x7E, 0x81, 0x81, 0x81, 0x42,  //  C
   	0xFF, 0x81, 0x81, 0x42, 0x3C,  //  D
   	0xFF, 0x91, 0x91, 0x91, 0x81}; //  E
// board
uint8_t *board[BOARD_ROW];
int board_size;
// board. .. writing, blank-.. .... ..
void boardWriter(int fontidx, int blank);
int main(void)
{
   	int i, j, total;
	// # of font data
   	total = sizeof(font85) / FONT_COL / sizeof(uint8_t);
	boardWriter(0,10);  // .. a, . .. 10
   	boardWriter(1,0);   // .. b, . .. 0
   	boardWriter(2,0);   // .. c, . .. 0
   	boardWriter(3,0);   // .. d, . .. 0
   	boardWriter(4,0);   // .. e, . .. 0
   	boardWriter(3,15);   // .. d, . .. 20
   	boardWriter(2,0);   // .. c, . .. 0
   	boardWriter(1,0);   // .. b, . .. 0
   	boardWriter(0,0);   // .. a, . .. 0
	printf("font data : %d\n", total);
   	printf("board info : %d X %d\n", board_size, BOARD_ROW);
   	printf("< B O A R D >\n");
   	for(i = 0 ; i < BOARD_ROW ; i++){
	   	for(j = 0 ; j < board_size ; j++)
		   	printf("%c ", board[i][j]);
	   	printf("\n");
   	}
	return 0;
}
void boardWriter(int fontidx, int blank)
{
   	int i, j, l;
   	static int board_offset = 0; // .. ... offset
   	uint8_t mask;
	if(blank)
	 	board_offset += blank;
	// memory reallocation
   	board_size = board_offset + FONT_COL + INTERVAL;
	for(i = 0 ; i < BOARD_ROW ; i++)
	   	board[i] = (uint8_t*)realloc(board[i], board_size);
	// writing on the board
   	for(i = 7, l = 0 ; i >= 0 ; i--, l++){
  		// row
	   	mask = 0b1 << i;
	   	for(j = 0 ; j < FONT_COL ; j++){    // col
		   	if((mask & font85[fontidx][j])){
			   	board[l][j+board_offset] = 'o';
		   	}
		   	else
		   	{
			   	board[l][j+board_offset] = ' ';
		   	}
	   	}
   	}
   	board_offset = board_size;;
}

