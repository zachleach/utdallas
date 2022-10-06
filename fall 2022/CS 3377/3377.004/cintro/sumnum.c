#include <stdio.h>
#include <stdlib.h>

void sumstore(int x, int y, int* dest);

int main(int argc, char** argv) {
  int z, x = 351, y = 333;
  sumstore(x, y, &z);
  printf("%i + %i = %i\n", x, y, z);
  return EXIT_SUCCESS;
}
