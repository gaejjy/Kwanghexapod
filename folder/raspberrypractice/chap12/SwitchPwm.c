#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>


#define SW1  23
#define SW2  24
#define PWM 14
#define EXIT_SUCC  0
#define EXIT_FAIL  1 

int main(void)
{
	int x = 0;
   	int dr1;
	int dr2;
	int orient;

	if(wiringPiSetupGpio() == -1) return EXIT_FAIL; 

	softPwmCreate (PWM, 0, 100) ; 

	pinMode(SW1, INPUT); pullUpDnControl(SW1, PUD_DOWN );
	pinMode(SW2, INPUT); pullUpDnControl(SW2,PUD_DOWN);

	while(1)
	{
		delay(10); 
		if((dr1 = digitalRead(SW1)) == 1)
	   	{
			printf("sw1 is pushed...\n");
            dr2 = 0;
		}

		if((dr2 = digitalRead(SW2)) == 1)
		{
			printf("sw2 is pushed...\n");
			dr1 = 0;
		}

        if(dr1 ==1){
	        if(x ==100){continue;}
			x +=2;
		}
		if(dr2 ==1){
			if(x == 0){continue;}
			x -=2;
		
			
		}
		softPwmWrite(PWM,x);
		delay(10);

    }
 return EXIT_SUCC;
}
