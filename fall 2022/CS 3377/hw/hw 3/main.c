/*
    09.07.2022 
    by zach leach (zcl190002)
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// TASK 1: Include the appropriate files.
int main(int argc, char** argv) {
    int32_t x = 3377;

    // TASK 2: 
    // Understand the assignment statements below.
    // Do not modify them.
    // Appropriately define the variables p, a, m, z, t 
    int *p = &x;       // p now contains the addr of x
    int **a = &p;
    int ***m = &a;
    int ****z = &m;
    int *****t = &z;
    
    // TASK 3: 
    // Your next task is to print the value of x by
    // recursively deferencing the above variables.
    // Complete the printf statments below.
    // The variable used should be as per the description
    // of the printf
    
    printf("x by recursive deref. of p: %d \n", *p);
    printf("x by recursive deref. of t: %d \n", **a);
    printf("x by recursive deref. of m: %d \n", ***m);
    printf("x by recursive deref. of z: %d \n", ****z);
    printf("x by recursive deref. of a: %d \n", *****t);
    
    char* c;
    
    // TASK 4: 
    // Find the sizes of c and p
    // Complete the statements below. Hint: sizeof()
    
    printf("size of c %d \n", (int) sizeof(c));
    printf("size of p %d \n", (int) sizeof(p));
    
    // TASK 5: 
    // What do you observe? c and p are pointers to two
    // different types. Are their sizes different?
    // Write a brief note justifying your observation
    // at the bottom of the file. 
    // Make sure it is commented.
    
    
    return EXIT_SUCCESS;
}

/*
    observation:
    pointer to a character and pointer to an integer have the same size (8),
    regardless of the fact that they are pointing to two different types.
*/







