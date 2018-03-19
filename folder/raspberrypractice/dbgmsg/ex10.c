#include <stdio.h>

#define REDS    "\x1b[31m"
#define REDE    "\x1b[0m"
#define DBGMSG_PREFX    REDS "<< DBGMSG >> "

#define DBGMSG_V6(msg,arg1) fprintf(stderr, \
						DBGMSG_PREFX "[%s %s %d] : " msg "\n" REDE, __FILE__, __func__, __LINE__, arg1)  

#define DBGMSG_V7(msg,...) fprintf(stderr, \
						DBGMSG_PREFX"[%s %s %d] : " msg "\n" REDE, __FILE__, __func__, \
																				__LINE__, ##__VA_ARGS__)  

int
main(void)
{
	int x = 10;
	double y = 3.14;
	char *str = "Hi";
	DBGMSG_V7("debug message v7, x = %d, str = %s, y = %.2f", x, str, y);
	DBGMSG_V7();
	return 0;
}

