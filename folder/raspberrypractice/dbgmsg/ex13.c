#include <stdio.h>
#include <unistd.h>

#ifdef DEBUG
#define REDS    "\x1b[31m"
#define REDE    "\x1b[0m"
#define DBGMSG_PREFX    REDS "<< DBGMSG >> "

#define DBGMSG(msg,...) fprintf(stderr, \
                        DBGMSG_PREFX"[%s %s %d] : " msg "\n" REDE, __FILE__, __func__, \
                                                                        __LINE__, ##__VA_ARGS__)

#else
#define DBGMSG(...)
#endif

void f(void);

int
main(void)
{
	int i;
	for(i = 1 ; i <= 20 ; i++) {
		DBGMSG("%d job processing", i);
		f();
	}
	printf("completed\n");
	return 0;
}

void f(void)
{
	sleep(1);
}
