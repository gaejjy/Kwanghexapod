#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int i;
	int sum=0;
	float avg = 0.0;

	for (i = 0;i<argc;i++)
	{
	  sum = sum+atoi(argv[i]);
    }

    printf("sum is %d and average is %f\n",sum,(float)sum/(argc-1));

return 0;
}
		
