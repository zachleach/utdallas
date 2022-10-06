// I learnt vi today
// my first c program
#include <stdio.h>
#include <stdlib.h>

//prototypes here
// my first comment
int 
main(int argc, char* argv[]) {
  int i;

  printf("argc = %i\n", argc);
  for (i = 0; i < argc; i++) {
    printf("argv[%i] = %s\n", i, argv[i]);
  }
// use atoi() to get the integer value
  return EXIT_SUCCESS;
}
