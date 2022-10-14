#include <stdlib.h>
#include <stdio.h>

#define MAX 100

//stack-buffer-overflow


int main() 
{
  void *p = malloc(7);
  p = 0; // The memory is leaked here.
  return 0;
}
