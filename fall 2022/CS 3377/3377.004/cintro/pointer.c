#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
//xx  this program demos pointers
int main(int argc, char** argv) {
  int32_t x = 351;
  int32_t* p;   // p is a pointer to a int32_t

  p = &x;       // p now contains the addr of x
  printf("&x is %p\n", &x);
  printf(" p is %p\n",  p);
  printf(" &p is %p\n",  &p);
  printf("&main is %p\n",  &main);
  printf("main is %p\n",  main);
  printf(" x is %d \n",  x);

  *p = 333;     // change value of x
  printf(" x is %" PRId32 "\n",  x);

  return EXIT_SUCCESS;
}
