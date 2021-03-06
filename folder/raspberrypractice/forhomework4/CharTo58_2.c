#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 4096
#define FONT_COL 5      // 폰트의 Column
#define BOARD_ROW 8     // board의 Row
#define INTERVAL 1;     // 문자간의 기본간격

uint8_t font85[][FONT_COL] = {
	0x7F, 0x88, 0x88, 0x88, 0x7F, //  A
	0xFF, 0x91, 0x91, 0x91, 0x6E, //  B
	0x7E, 0x81, 0x81, 0x81, 0x42, //  C
	0xFF, 0x81, 0x81, 0x42, 0x3C, //  D
	0xFF, 0x91, 0x91, 0x91, 0x81, //  E
	0xFF, 0x90, 0x90, 0x90, 0x80, //  F
	0x7E, 0x81, 0x89, 0x89, 0x4E, //  G
	0xFF, 0x10, 0x10, 0x10, 0xFF, //  H
	0x81, 0x81, 0xFF, 0x81, 0x81, //  I
	0x06, 0x01, 0x01, 0x01, 0xFE, //  J
	0xFF, 0x18, 0x24, 0x42, 0x81, //  K
	0xFF, 0x01, 0x01, 0x01, 0x01, //  L
	0xFF, 0x40, 0x30, 0x40, 0xFF, //  M
	0xFF, 0x40, 0x30, 0x08, 0xFF, //  N
	0x7E, 0x81, 0x81, 0x81, 0x7E, //  O
	0xFF, 0x88, 0x88, 0x88, 0x70, //  P
	0x7E, 0x81, 0x85, 0x82, 0x7D, //  Q
	0xFF, 0x88, 0x8C, 0x8A, 0x71, //  R
	0x61, 0x91, 0x91, 0x91, 0x8E, //  S
	0x80, 0x80, 0xFF, 0x80, 0x80, //  T
	0xFE, 0x01, 0x01, 0x01, 0xFE, //  U
	0xF0, 0x0C, 0x03, 0x0C, 0xF0, //  V
	0xFF, 0x02, 0x0C, 0x02, 0xFF, //  W
	0xC3, 0x24, 0x18, 0x24, 0xC3, //  X
	0xE0, 0x10, 0x0F, 0x10, 0xE0, //  Y
	0x83, 0x85, 0x99, 0xA1, 0xC1, //  Z
	0x06, 0x29, 0x29, 0x29, 0x1F, //  a
	0xFF, 0x09, 0x11, 0x11, 0x0E, //  b
	0x1E, 0x21, 0x21, 0x21, 0x12, //  c
	0x0E, 0x11, 0x11, 0x09, 0xFF, //  d
	0x0E, 0x15, 0x15, 0x15, 0x0C, //  e
	0x08, 0x7F, 0x88, 0x80, 0x40, //  f
	0x30, 0x49, 0x49, 0x49, 0x7E, //  g
	0xFF, 0x08, 0x10, 0x10, 0x0F, //  h
	0x00, 0x00, 0x5F, 0x00, 0x00, //  i
	0x02, 0x01, 0x21, 0xBE, 0x00, //  j
	0xFF, 0x04, 0x0A, 0x11, 0x00, //  k
	0x00, 0x81, 0xFF, 0x01, 0x00, //  l
	0x3F, 0x20, 0x18, 0x20, 0x1F, //  m
	0x3F, 0x10, 0x20, 0x20, 0x1F, //  n
	0x0E, 0x11, 0x11, 0x11, 0x0E, //  o
	0x3F, 0x24, 0x24, 0x24, 0x18, //  p
	0x10, 0x28, 0x28, 0x18, 0x3F, //  q
	0x1F, 0x08, 0x10, 0x10, 0x08, //  r
	0x09, 0x15, 0x15, 0x15, 0x02, //  s
	0x20, 0xFE, 0x21, 0x01, 0x02, //  t
	0x1E, 0x01, 0x01, 0x02, 0x1F, //  u
	0x1C, 0x02, 0x01, 0x02, 0x1C, //  v
	0x1E, 0x01, 0x0E, 0x01, 0x1E, //  w
	0x11, 0x0A, 0x04, 0x0A, 0x11, //  x
	0x00, 0x39, 0x05, 0x05, 0x3E, //  y
	0x11, 0x13, 0x15, 0x19, 0x11, //  z
	0x7E, 0x89, 0x91, 0xA1, 0x7E, //  0
	0x00, 0x41, 0xFF, 0x01, 0x00, //  1
	0x43, 0x85, 0x89, 0x91, 0x61, //  2
	0x42, 0x81, 0x91, 0x91, 0x6E, //  3
	0x18, 0x28, 0x48, 0xFF, 0x08, //  4
	0xF2, 0x91, 0x91, 0x91, 0x8E, //  5
	0x1E, 0x29, 0x49, 0x89, 0x86, //  6
	0x80, 0x8F, 0x90, 0xA0, 0xC0, //  7
	0x6E, 0x91, 0x91, 0x91, 0x6E, //  8
	0x70, 0x89, 0x89, 0x8A, 0x7C, //  9
};

uint8_t *board[BOARD_ROW];
uint8_t *board2[BOARD_ROW];
int board_size;


void boardWriter(int fontidx, int blank);
void ReadAndWirte(char* in_buf);
void WriteDotFile(char* out_fname);

int main(int argc, char* argv[])
{
	char buf[SIZE] = {0};
	char *dotbuf;
	int nRead;
	int nWrite;
	int i,j,k;
	int charnum;

	if(argc != 2){
		printf("usage : ./getmsg filename...\n");
		return 1;
	}

	int fd;
    FILE *fp1;

	 // check file existance
	 if((fd = open(argv[1], O_RDONLY)) == -1 && errno == ENOENT)
	 {
       printf("file is no exists, so i will make file..\n");
	 }
	 else
	 {
	   close(fd);
	   printf("'%s' file already exists.\nfail!\n", argv[1]);
	   return 1;
	 }

	 nRead = read(STDIN_FILENO, buf, sizeof(buf));
	     // check read error
	 if(nRead == -1)
	 {
	   printf("read error.\nfail\n");
	   return 1;
	 }
      if(!isAllowString(buf))
  	  {
	         printf("fail!\n");
			 return 1;
	  }

	  ReadAndWirte(buf);
	  WriteDotFile(argv[1]);


	  /*
	  printf("i will show your word to dot..\n");
	  printf("board info : %d X %d\n", board_size, BOARD_ROW);
	  printf("< B O A R D >\n");
	  for(i = 0 ; i < BOARD_ROW ; i++){
		  for(j = 0 ; j < board_size ; j++)
			  printf("%c ", board[i][j]);
		  printf("\n");
	  }
      */

	  printf("i will show your outfile dot...\n");
      k = 0;
      if((fp1 = fopen(argv[1], "r")) != NULL)
	 {
         for(i = 0 ; i < BOARD_ROW ; i++)      	  
         board2[i] = (uint8_t*)realloc(board[i], board_size);
          charnum = board_size/ (FONT_COL+1);            
		 uint8_t* copy2;
		 printf("board size is %d...\n",board_size);
	     copy2 =  (uint8_t*)malloc(BOARD_ROW*board_size*sizeof(uint8_t));
		 fread(copy2,BOARD_ROW*board_size*sizeof(uint8_t),1,fp1);
         
	     for(i = 0 ; i < BOARD_ROW ; i++){
        for(j = 0 ; j <  board_size ; j++)
		{
			printf("%c ",*(copy2 + ((i*board_size) +k )));
			if(k ==(((FONT_COL+1)*charnum)))k=0;
			k++;
		}
		printf("\n");
           
	 }
	 }  
	  return 0;
}
int isAllowChar(char ch){	    
	    if(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9') ||
				            ch == '.' || ch == ','|| ch == '?' || ch == '\'' || ch == '!' || ch == '/' || 
							            ch == '\t' || ch ==' ')
		 return 1;
	     return 0;
}
int isAllowString(char *string){
	    int i;
		int length = strlen(string);
	    for(i = 0; i < length-1; i++){
		if(!isAllowChar(string[i]))
		return 0;
		 }
	   	return 1;
}
void ReadAndWirte(char* in_buf)
{
	int i = 0;
	int size = 0;
	size = strlen(in_buf)-1;
	int charnum;
	for(i = 0;i<size;i++)
	{
		char target = in_buf[i];
		if(target >='a' && target<=122)
		{
	        charnum = target - 97;
	        boardWriter(charnum + 26, 0);     		
		}
		else if(target >='A' && target <='Z')
		{
			charnum = target - 65;
			boardWriter(charnum,0);

		}
		else if(target >=48 && target <=57)
		{
			charnum = target - 48;
			boardWriter(charnum + 52,0);
		}	
	}
	
}
void WriteDotFile(char* out_fname)
{
 FILE *fp;
 uint8_t* copy;
 int i,j,k;
 int charnum;
 copy = (uint8_t*)malloc(BOARD_ROW*board_size*sizeof(uint8_t));
 
 charnum = board_size/ (FONT_COL+1);//means interval...
 printf("number of char is %d...\n",charnum);
 printf("board size is %d...\n",board_size);

 k = 0;
 for(i = 0 ; i < BOARD_ROW ; i++){
	 for(j = 0 ; j < board_size ; j++)
	 {
	   
       *(copy + ((i*board_size) +k ))  = board[i][j];
       if(k ==(((FONT_COL+1)*charnum)))k=0;
	   k++;
	 }
 }
 
 
 
 printf("k value is %d...\n",k);
 k = 0;
 for(i = 0 ; i < BOARD_ROW ; i++){
	  for(j = 0 ; j <  board_size ; j++)
	  {
	       
		   printf("%c ",*(copy + ((i*board_size) +k )));
		   if(k ==(((FONT_COL+1)*charnum)))k=0;
		   k++;
	  }
	  printf("\n");
	
 }


 
 
 if(out_fname!=NULL)
 {
	 if((fp = fopen(out_fname,"w"))!=NULL)
	 {
		 fwrite(copy,board_size*BOARD_ROW*sizeof(uint8_t),1,fp);
		 printf("write success...\n");
		 fclose(fp);

	 }
	 
	 else
	 {
		 printf("fopen is error!\n");
		 fclose(fp);
		 exit(1);
	 }
 } 
}
void boardWriter(int fontidx, int blank)
{
   	int i, j, l;
   	static int board_offset = 0; // 현재 문자의 offset
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
	   	for(j = 0 ; j < FONT_COL ; j++){
			// col
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
