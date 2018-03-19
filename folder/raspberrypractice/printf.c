#include <stdio.h>

int main()
{
	int x = 10;
	int r;
	int max;
	char *string = "hello, world";
	r = printf("x = %d\n",x);
	printf("r returned by printf() = %d\n\n",r);
	printf(":%%s:         :%s:\n",string);
   	printf(":%%10s:       :%10s:\n",string);
   	printf(":%%15s:       :%15s:\n",string);
   	printf(":%%.10s:      :%.10s:\n",string);
   	printf(":%%-10s:      :%-10s:\n",string);
   	printf(":%%.15s:      :%.15s:\n",string);
   	printf(":%%15.10s:    :%15.10s:\n",string);
   	printf(":%%-15.10s:   :%-15.10s:\n\n",string);
   	printf(":%%.5d:        :%.5d:\n",123456789);
   	printf(":%%.5d:        :%.5d:\n",123);
   	printf(":%%.10d:        :%.10d:\n",123);
   	printf(":%%.5f:        :%.5f:\n\n",(double)123);
	printf("....\n");
   	printf("%%#.8x        %#.8x\n",(unsigned)123);
   	printf("0x%%08x       0x%08x\n",(unsigned)123);
   	printf("%%#10x        %#010x\n\n",(unsigned)123);
   	printf("....\n");
   	printf("%%.2d:%%.2d:%%.2d        %.2d:%.2d:%.2d\n",1,59,59);
   	printf("%%.2d:%%.2d:%%.2d        %.2d:%.2d:%.2d\n",1,1,1);
   	printf("%%.2d:%%.2d:%%.2d        %.2d:%.2d:%.2d\n",1,10,100);
   	printf("%%02d:%%02d:%%02d        %02d:%02d:%02d\n",1,59,59);
   	printf("%%02d:%%02d:%%02d        %02d:%02d:%02d\n",1,1,1);
   	printf("%%02d:%%02d:%%02d        %02d:%02d:%02d\n",1,10,100);
   	printf("\n"); printf(":%%-d:   :%-d:\n", x);
   	printf(":%%+d:   :%+d:\n", x);
   	printf(":%% d:   :% d:\n", x);
   	printf(":%%#x:   :%#x:\n", x);
   	printf(":%%#o:   :%#o:\n", x);
   	printf(":%%010d:   :%010d:\n", x);
   	printf("\n");
   	max=10;
   	printf("%%*.*s        :%*.*s:\n",15,max,string);
   	return 0;
}
