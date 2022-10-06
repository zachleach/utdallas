#include <stdlib.h>
int 
main(int argc, char** argv) 
{
  int* p = (int *) malloc(4);
  free(p);
  int* p1 = (int *) malloc(4);
  *p1 = 2;
  *p = 1;  // causes a segmentation fault
   
  return 0;
}
