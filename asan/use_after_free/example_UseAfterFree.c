#include <stdlib.h>
//use after free

int main(int argc, char **argv) 
{
  int *array = (int*)malloc(100);
  free(array);
  return array[10];  // BOOM
}
