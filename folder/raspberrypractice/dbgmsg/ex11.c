#include <stdio.h>
#define REDS    "\x1b[31m"
#define REDE    "\x1b[0m"
#define DBGMSG_PREFX    REDS "<< DBGMSG >> "

#define DBGMSG(msg,...) fprintf(stderr, \
                        DBGMSG_PREFX"[%s %s %d] : " msg "\n" REDE, __FILE__, __func__, \
                                                                                __LINE__, ##__VA_ARGS__)

void change(int, int*, int**);
int gvala = 1;
int gvalb = 2;

int 
main(void)
{
	int val	= gvala;	
	int *p1	= &gvala;
	int *p2	= &gvala;

	DBGMSG("p1:%p, p2:%p", p1, p2);
	change(val, p1, &p2);
	DBGMSG("p1:%p, p2:%p", p1, p2);
	printf("val:%d, *p1:%d, *p2:%d\n", val, *p1, *p2);

	return 0;
}

void 
change(int tmpval, int* tmpp1, int** tmpp2)
{
	tmpval	= gvalb;
	tmpp1	= &gvalb;
	*tmpp2	= &gvalb;
	DBGMSG("Here!");
	DBGMSG("tmpval:%d, tmpp1:%p, tmpp2:%p", tmpval, tmpp1, tmpp2);
}
