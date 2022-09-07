// TASK 1: Include the appropriate files.
main(int argc, char** argv) 
{
  int32_t x = 3377;

  // TASK 2: 
  // Understand the assignment statements below.
  // Do not modify them.
  // Appropriately define the variables p, a, m, z, t 
  int *p = &x;       // p now contains the addr of x
  int **a = &p;
  int ***m = &a;
  int ****z = &m;
  int *****t = &z

  // TASK 3: 
  // Your next task is to print the value of x by
  // recursively deferencing the above variables.
  // Complete the printf statments below.
  // The variable used should be as per the description
  // of the printf

  printf("x by recursive deref. of p: %d \n",  );
  printf("x by recursive deref. of t: %d \n",  );
  printf("x by recursive deref. of m: %d \n",  );
  printf("x by recursive deref. of z: %d \n",  );
  printf("x by recursive deref. of a: %d \n",  );

  char* c;

  // TASK 4: 
  // Find the sizes of c and p
  // Complete the statements below. Hint: sizeof()

  printf("size of c %d \n", );
  printf("size of p %d \n", );

  // TASK 5: 
  // What do you observe? c and p are pointers to two
  // different types. Are their sizes different?
  // Write a brief note justifying your observation
  // at the bottom of the file. 
  // Make sure it is commented.


  return EXIT_SUCCESS;
}

/* your observation below
 *
 */
