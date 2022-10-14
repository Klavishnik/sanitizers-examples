#include <stdlib.h>
#include <stdio.h>

//heap-buffer-overflow

int main() 
{

  int *array = (int*)malloc(4);

  array[0] = 0;   //4  byte
  array[1] = 1;   //8  byte
  array[2] = 2;   //12 byte

  // we have 3 bytes, but use 3*sizeof(int) 
  free(array);
  printf("%lu", sizeof(int));
  return 1;
}
