#include <stdio.h>

void change(int, int*, int**);

int gvala = 1;
int gvalb = 2;

int 
main(void)
{
	int val	= gvala;	
	int *p1	= &gvala;
	int *p2	= &gvala;

	change(val, p1, &p2);

	printf("val:%d, *p1:%d, *p2:%d\n", val, *p1, *p2);

	return 0;
}

void 
change(int tmpval, int* tmpp1, int** tmpp2)
{
	tmpval	= gvalb;
	tmpp1	= &gvalb;
	*tmpp2	= &gvalb;
}
