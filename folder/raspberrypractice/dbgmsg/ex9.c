#include <stdio.h>

#define DBGMSG_V1 printf("%s %s %d\n", __FILE__, __func__, __LINE__)  

#define DBGMSG_V2 fprintf(stderr, \
						"%s %s %d\n", __FILE__, __func__, __LINE__)  

#define DBGMSG_V3(msg) fprintf(stderr, \
						"%s %s %d " msg "\n", __FILE__, __func__, __LINE__)  

#define DBGMSG_V4(msg) fprintf(stderr, \
						"[%s %s %d] : " msg "\n", __FILE__, __func__, __LINE__)  

#define DBGMSG_V5(msg,arg1) fprintf(stderr, \
						"[%s %s %d] : " msg "\n", __FILE__, __func__, __LINE__, arg1)  

#define REDS    "\x1b[31m"
#define REDE    "\x1b[0m"
#define DBGMSG_PREFX    REDS "<< DBGMSG >> " 

#define DBGMSG_V6(msg,arg1) fprintf(stderr, \
						DBGMSG_PREFX "[%s %s %d] : " msg "\n" REDE, __FILE__, __func__, __LINE__, arg1)  


void f(void);

int
main(void)
{
	DBGMSG_V1;
	DBGMSG_V2;
	DBGMSG_V3("debug message v3");
	DBGMSG_V4("debug message v4");
	f();
	return 0;
}

void
f(void)
{
	int x = 10;
	DBGMSG_V5("debug message v5, x = %d", x);
	DBGMSG_V6("debug message v6, x = %d", x);
}


