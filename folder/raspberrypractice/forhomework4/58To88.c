#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#define SDATA       6    // Serial Input Data
#define STR_CLK     13   // Storage Register Clock(LATCH)
#define SHR_CLK     19   // Shift Register Clock
#define SHR_CLEAR   26   // Shift Register Clear
#define ROW 8
#define COL 8 
 
uint8_t *copy;
uint8_t **mat;

void readInputFile(char *in_fname)
{
  FILE *fp;
  int i,j;
  int len;
  int charnum; 
  if((fp = fopen(in_fname, "r")) != NULL)
  {
    fseek(fp, 0L, SEEK_END);
    len = ftell(fp);
	charnum = len/48;
    printf("charc num is %d...\n",charnum);
    copy = (uint8_t*)malloc(ROW *COL *charnum *sizeof(uint8_t));
    fread(copy,len,1,fp);
	fclose(fp);
    	
  }
  for(i = 0;i<len;i++)
  {
	  if(i %5 == 0)
		  printf("\n");
	  printf("%c ",(char)copy[i]);
  }

  
}

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
void dot(int row, int col)
{
	uint8_t row8, col8; uint16_t tmp;
   	row8 = 1 << (8-row);
   	col8 = ~(1 << (8-col));
   	tmp = (row8<<8) | col8;
   	set16(tmp);
}
int cnt;
void * thr_fn1(void *arg)
{
   	while(1){
	   	usleep(200000);
	   	cnt++;
   	}
   	return((void *)0);
}
int main(int argc, char *argv[])
{
   	int i, j;
   	int col;
   	pthread_t tid;

    col = sizeof(mat) / ROW;
	init();
   	pthread_create(&tid, NULL, thr_fn1, NULL);

	if(argc != 2)
   	{
	 printf("usage : getmsg filename\nfail!\n");
	 return 1;
	}

    readInputFile(argv[1]);   
   /* while(1)
	   	for(j = 0 ; j < COL ; j++)
		   	for(i = 0 ; i < ROW ; i++)
			   	if(mat[i][(j+cnt)%col] == 1)
				   	dot(i+1,j+1);*/
   	return 1;
}


