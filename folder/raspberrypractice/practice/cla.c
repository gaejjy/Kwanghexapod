#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
     int idx;

     for(idx = 0; idx <argc; idx++)
     for(idx = 0; argv[idx] != NULL; idx++)
          printf("artv[%d]: %s\n",idx, argv[idx]);
     exit(0);
}
