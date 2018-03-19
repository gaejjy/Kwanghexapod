#include <stdio.h>

void change(int** t1, int** t2)
{
	int* temp;
	temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

int main()
{
	int target1 = 11111;
	int target2 = 22222;

	int *p1 = &target1;
	int *p2 = &target2;

	printf("target1's value is %d  and target2's value is %d\n",*p1,*p2);


	change(&p1,&p2);

	printf("after change  target1's value is %d  and target2's value is %d\n",*p1,*p2);

	return 0;
}

