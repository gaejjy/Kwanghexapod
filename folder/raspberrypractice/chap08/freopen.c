#include <stdio.h>
int main(void)
{
	char *fname = "test";
	FILE *fp;
	printf("First printf is on the screen.\n");
	if((fp = freopen(fname, "w", stdout)) == NULL){
		fprintf(stderr,"freopen\n");
		return 1;
	}
	printf("Second printf is in this file.\n");
	return 0;
}

