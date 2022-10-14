#include <stdlib.h>
#include <stdio.h>
#define MAX 100

//heap-buffer-overflow

int main() 
{

  int *array = (int*)malloc(MAX * sizeof(int));
  array[0] = 0;
  int res = array[MAX+2];  // BOOM
  free(array);
  printf("%i", res);
  return res;
}
