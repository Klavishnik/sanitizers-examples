#include <stdlib.h>
#include <stdio.h>

#define MAX 100

//stack-buffer-overflow

int main() 
{
  int array[MAX];
  array[1] = 0;
  int res = array[MAX+2];  // BOOM
  printf("%i", res);
  return res;
}
