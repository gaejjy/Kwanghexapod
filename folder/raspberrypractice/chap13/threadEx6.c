#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <wiringPi.h>
#define LED     4
#define SW      23
void *thr_fn(void *arg);
struct timespec diffTimespec(struct timespec t1, struct timespec t2);
int main(void)
{
   	int err;
   	int isPushed = 0;
   	pthread_t tid;
	if(wiringPiSetupGpio() == -1) {         // wiringPi ...
	   	printf("wiringPiSetupGpio error\n");
	   	return 1;
   	}
   	pinMode(LED, OUTPUT);
   	pinMode(SW, INPUT);
   	pullUpDnControl(SW, PUD_UP);   // .. pull UP .. ON
while(1){
   	if(digitalRead(SW) == 0 && isPushed == 0){
	   	err = pthread_create(&tid, NULL, thr_fn, NULL);
	   	if (err != 0){
		   	fprintf(stderr, "cant create thread 1");
		   	exit(1);
	   	}
	   	isPushed = 1;
   	}else
	   	if(digitalRead(SW) == 1){
		   	isPushed = 0;
	   	}
}
return 0;
}
void * thr_fn(void *arg)
{
   	int i = 0;
   	pthread_t tid;
	tid = pthread_self();
   	printf("(0x%lx) thread start!\n", (unsigned long)tid);
	for(i = 0 ; i < 10 ; i++){
	   	digitalWrite(LED, HIGH);
	   	printf("(0x%lx) LED ON!\n", (unsigned long)tid);
	   	usleep(100000);
	   	digitalWrite(LED, LOW);
	   	printf("(0x%lx) LED OFF!\n", (unsigned long)tid);
	   	usleep(100000);
   	}
   	printf("(0x%lx) thread end!\n", (unsigned long)tid);
   	return((void *)0);
}

