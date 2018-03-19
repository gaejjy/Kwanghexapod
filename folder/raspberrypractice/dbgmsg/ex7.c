#include <stdio.h>

void change(int, int*, int**);

int gvala = 1;
int gvalb = 2;
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#define DBGMSG_PREFX    ANSI_COLOR_RED "<< DBGMSG >> " ANSI_COLOR_RESET

int 
main(void)
{
	int val	= gvala;	
	int *p1	= &gvala;
	int *p2	= &gvala;

	fprintf(stderr, DBGMSG_PREFX "[%d] p1:%p, p2:%p\n", __LINE__, p1, p2);
	change(val, p1, &p2);
	fprintf(stderr, DBGMSG_PREFX "[%d] p1:%p, p2:%p\n", __LINE__, p1, p2);
	printf("val:%d, *p1:%d, *p2:%d\n", val, *p1, *p2);

	return 0;
}

void 
change(int tmpval, int* tmpp1, int** tmpp2)
{
	tmpval	= gvalb;
	tmpp1	= &gvalb;
	*tmpp2	= &gvalb;
	fprintf(stderr, DBGMSG_PREFX "[%s]\n", __func__);
	fprintf(stderr, DBGMSG_PREFX "tmpval:%d, tmpp1:%p, tmpp2:%p\n", tmpval, tmpp1, tmpp2);
}
