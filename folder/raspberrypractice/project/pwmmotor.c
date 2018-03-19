#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#define LED1 13

int main(void)
{
	int num;
   	if (wiringPiSetupGpio() == -1)
		    exit (1) ;

	pinMode(LED1,PWM_OUTPUT); 
	pwmSetMode(PWM_MODE_MS );
	pwmSetClock ( 400 ); 
	pwmSetRange ( 1024 );

printf("start!! please input your number...\n");

	while(1)
	{
	  printf("intpu : ");
	  scanf("%d",&num);
      if(num == -1)
	  {
	   printf("over..\n");
       break;
	  }
	  else{

      pwmWrite(LED1,num);
	  delay(100);
	  continue;
	  }
	}
return 0;
}
	  


