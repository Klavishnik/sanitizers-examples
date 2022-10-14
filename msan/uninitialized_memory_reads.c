#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) 
{
  int* a = (int*)malloc(20 * sizeof(int));

  a[0] = 0;
  if (a[2])  //un init 
    printf("xx\n");

  free(a);
  return 0;
}
